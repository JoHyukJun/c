#include <gtk/gtk.h>
#include "chart.h"

static GraphData graphs[NUM_GRAPHS];

static gboolean update_values(gpointer user_data) {
    GtkWidget *drawing_area = GTK_WIDGET(user_data);

    // 그래프 데이터 업데이트
    update_graphs(graphs, NUM_GRAPHS);

    // 화면을 다시 그리도록 요청
    gtk_widget_queue_draw(drawing_area);

    // TRUE를 반환하여 타이머가 계속 실행되도록 함
    return TRUE;
}

static void draw_callback(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer data) {
    (void)data;

    // 그래프 그리기
    draw_graphs(area, cr, width, height, graphs, NUM_GRAPHS);
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    (void)user_data;
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Swing Chart");
    gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);

    GtkWidget *grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    for (int i = 0; i < NUM_CHARTS; i++) {
        GtkWidget *drawing_area = gtk_drawing_area_new();
        gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), draw_callback, &graphs[i], NULL);
        gtk_widget_set_size_request(drawing_area, 400, 300);

        // 그래프 데이터를 drawing_area에 저장
        g_object_set_data(G_OBJECT(drawing_area), "graph_data", &graphs[i]);

        // 그리드에 drawing_area 추가
        gtk_grid_attach(GTK_GRID(grid), drawing_area, i % 3, i / 3, 1, 1);

        // 초기 값을 설정하고 화면을 다시 그리도록 요청
        update_values(drawing_area);

        // g_timeout_add를 사용하여 update_values 함수를 100밀리초마다 호출
        g_timeout_add(100, update_values, drawing_area);
    }

    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    // 그래프 데이터 초기화
    for (int j = 0; j < NUM_CHARTS; j++) {
        graphs[j].num_values = NUM_VALUES;
        graphs[j].max_value = 100.0;
        graphs[j].min_value = 0.0;
    }

    GtkApplication *app = gtk_application_new("com.unluckystrike.SwingChart", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}