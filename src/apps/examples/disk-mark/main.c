#include <gtk/gtk.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/param.h>
#include <sys/mount.h>

#define TEST_FILE_NAME "./tmp/diskmark_test.tmp"
#define TEST_SIZE_MB 100

typedef struct {
    GtkWidget *combo;
    GtkWidget *info_label;
    GtkWidget *result_label;
    GPtrArray *mount_paths;
} AppWidgets;

void format_bytes(char *out, size_t out_size, long long bytes) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double size = bytes;

    while (size > 1024 && i < 4) {
        size /= 1024.0;
        i++;
    }

    snprintf(out, out_size, "%.2f %s", size, units[i]);
}

void update_disk_info(GObject *obj, GParamSpec *pspec, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;

    if (!widgets->mount_paths || widgets->mount_paths->len == 0) {
        gtk_label_set_text(GTK_LABEL(widgets->info_label), "마운트된 디스크가 없습니다.");
        return;
    }

    int idx = gtk_drop_down_get_selected(GTK_DROP_DOWN(widgets->combo));
    if (idx == GTK_INVALID_LIST_POSITION || idx >= (int)widgets->mount_paths->len) {
        gtk_label_set_text(GTK_LABEL(widgets->info_label), "디스크를 선택하세요.");
        return;
    }

    char *mount_path = g_ptr_array_index(widgets->mount_paths, idx);
    struct statfs fs;
    if (statfs(mount_path, &fs) != 0) {
        gtk_label_set_text(GTK_LABEL(widgets->info_label), "디스크 정보 가져오기 실패.");
        return;
    }

    long long total = (long long)fs.f_blocks * fs.f_bsize;
    long long free  = (long long)fs.f_bavail * fs.f_bsize;
    long long used  = total - free;

    char total_str[64], used_str[64], free_str[64];
    format_bytes(total_str, sizeof(total_str), total);
    format_bytes(used_str, sizeof(used_str), used);
    format_bytes(free_str, sizeof(free_str), free);

    char info[512];
    snprintf(info, sizeof(info),
             "경로: %s\n전체: %s\n사용 중: %s\n남은 공간: %s",
             mount_path, total_str, used_str, free_str);

    gtk_label_set_text(GTK_LABEL(widgets->info_label), info);
}

void populate_volumes(AppWidgets *widgets) {
    DIR *d;
    struct dirent *dir;

    d = opendir("/Volumes");
    if (!d) return;

    widgets->mount_paths = g_ptr_array_new_with_free_func(g_free);
    GtkStringList *str_list = gtk_string_list_new(NULL);

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "/Volumes/%s", dir->d_name);
            gtk_string_list_append(str_list, full_path);
            g_ptr_array_add(widgets->mount_paths, g_strdup(full_path));
        }
    }
    closedir(d);

    gtk_drop_down_set_model(GTK_DROP_DOWN(widgets->combo), G_LIST_MODEL(str_list));
}

char *get_selected_mount(AppWidgets *widgets) {
    int idx = gtk_drop_down_get_selected(GTK_DROP_DOWN(widgets->combo));
    if (idx == GTK_INVALID_LIST_POSITION || idx >= (int)widgets->mount_paths->len) return NULL;
    return (char *)g_ptr_array_index(widgets->mount_paths, idx);
}

void write_speed_test(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    char *mount_path = get_selected_mount(widgets);
    if (!mount_path) {
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "디스크를 선택하세요.");
        return;
    }

    char test_file[PATH_MAX];
    snprintf(test_file, sizeof(test_file), "%s/%s", mount_path, TEST_FILE_NAME);

    FILE *fp = fopen(test_file, "wb");
    if (!fp) {
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "쓰기 파일 열기 실패");
        return;
    }

    char *block = malloc(1024 * 1024);
    memset(block, 0, 1024 * 1024);

    clock_t start = clock();
    for (int i = 0; i < TEST_SIZE_MB; i++) {
        fwrite(block, 1, 1024 * 1024, fp);
    }
    fflush(fp);
    fclose(fp);
    free(block);

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = TEST_SIZE_MB / duration;

    char result[256];
    snprintf(result, sizeof(result), "%s\n쓰기 속도: %.2f MB/s", test_file, speed);
    gtk_label_set_text(GTK_LABEL(widgets->result_label), result);
}

void read_speed_test(GtkButton *button, gpointer user_data) {
    AppWidgets *widgets = (AppWidgets *)user_data;
    char *mount_path = get_selected_mount(widgets);
    if (!mount_path) {
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "디스크를 선택하세요.");
        return;
    }

    char test_file[PATH_MAX];
    snprintf(test_file, sizeof(test_file), "%s/%s", mount_path, TEST_FILE_NAME);

    FILE *fp = fopen(test_file, "rb");
    if (!fp) {
        gtk_label_set_text(GTK_LABEL(widgets->result_label), "읽기 파일이 없습니다. 먼저 쓰기 테스트를 실행하세요.");
        return;
    }

    char *block = malloc(1024 * 1024);
    size_t total_read = 0;

    clock_t start = clock();
    while (1) {
        size_t bytes = fread(block, 1, 1024 * 1024, fp);
        if (bytes == 0) break;
        total_read += bytes;
    }
    fclose(fp);
    free(block);

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (total_read / (1024.0 * 1024.0)) / duration;

    char result[256];
    snprintf(result, sizeof(result), "%s\n읽기 속도: %.2f MB/s", test_file, speed);
    gtk_label_set_text(GTK_LABEL(widgets->result_label), result);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window, *vbox, *hbox, *combo, *info_label, *result_label, *btn_write, *btn_read;

    AppWidgets *widgets = g_malloc0(sizeof(AppWidgets));

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "macOS Disk Mark");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 240);
    gtk_window_set_child(GTK_WINDOW(window), gtk_box_new(GTK_ORIENTATION_VERTICAL, 10));
    vbox = gtk_window_get_child(GTK_WINDOW(window));

    gtk_widget_set_margin_top(vbox, 10);
    gtk_widget_set_margin_bottom(vbox, 10);
    gtk_widget_set_margin_start(vbox, 10);
    gtk_widget_set_margin_end(vbox, 10);

    combo = gtk_drop_down_new(NULL, NULL);
    gtk_box_append(GTK_BOX(vbox), combo);
    widgets->combo = combo;

    info_label = gtk_label_new("디스크 정보를 불러오는 중...");
    gtk_label_set_xalign(GTK_LABEL(info_label), 0.0);
    gtk_box_append(GTK_BOX(vbox), info_label);
    widgets->info_label = info_label;

    result_label = gtk_label_new("결과가 여기에 표시됩니다.");
    gtk_label_set_xalign(GTK_LABEL(result_label), 0.0);
    gtk_box_append(GTK_BOX(vbox), result_label);
    widgets->result_label = result_label;

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(vbox), hbox);

    btn_write = gtk_button_new_with_label("쓰기 테스트");
    gtk_box_append(GTK_BOX(hbox), btn_write);
    g_signal_connect(btn_write, "clicked", G_CALLBACK(write_speed_test), widgets);

    btn_read = gtk_button_new_with_label("읽기 테스트");
    gtk_box_append(GTK_BOX(hbox), btn_read);
    g_signal_connect(btn_read, "clicked", G_CALLBACK(read_speed_test), widgets);

    populate_volumes(widgets);
    g_signal_connect(widgets->combo, "notify::selected", G_CALLBACK(update_disk_info), widgets);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.diskmark.macplus", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}