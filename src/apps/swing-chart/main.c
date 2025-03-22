#include <gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <time.h>


static double values[1000];
static int num_values = sizeof(values) / sizeof(values[0]);
static double max_value = 100.0;

static gboolean update_values(user_data)
gpointer user_data;
{
    GtkWidget *drawing_area = GTK_WIDGET(user_data);

    // 랜덤 값을 생성하기 위해 시드 설정
    srand(time(NULL));

    // 랜덤 값 배열 생성
    for (int i = 0; i < num_values; i++) {
        values[i] = (double)(rand() % 101); // 0에서 100 사이의 랜덤 값
    }

    // 화면을 다시 그리도록 요청
    gtk_widget_queue_draw(drawing_area);

    // TRUE를 반환하여 타이머가 계속 실행되도록 함
    return TRUE;
}

static void draw_callback(area, cr, width, height, data)
GtkDrawingArea *area;
cairo_t *cr;
int width;
int height;
gpointer data;
{
    (void)data;

    double x_step = (double)width / (num_values - 1);

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 2);
    
    cairo_move_to(cr, 0, height - 10);
    cairo_line_to(cr, width, height - 10);
    
    cairo_move_to(cr, 10, 0);
    cairo_line_to(cr, 10, height);
    
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 0.2, 0.4, 0.8);
    cairo_set_line_width(cr, 3);
    
    for (int i = 0; i < num_values; i++)
    {
        double x = i * x_step;
        double y = height - (values[i] / max_value) * (height - 20);
        
        if (i == 0)
            cairo_move_to(cr, x, y);
        else
            cairo_line_to(cr, x, y);
    }
    
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 1, 0, 0);
    
    for (int i = 0; i < num_values; i++)
    {
        double x = i * x_step;
        double y = height - (values[i] / max_value) * (height - 20);
        
        cairo_arc(cr, x, y, 4, 0, 2 * 3.1416);
        cairo_fill(cr);
    }
}   

static void on_activate(app, user_data)
GtkApplication *app;
gpointer user_data;
{
    (void)user_data;
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Swing Chart");
    gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);

    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), draw_callback, NULL, NULL);

    // GTK4에서는 gtk_container_add() 대신 gtk_window_set_child() 사용
    gtk_window_set_child(GTK_WINDOW(window), drawing_area);

    gtk_widget_show(window);

    g_timeout_add(1, update_values, drawing_area);
}

int main(argc, argv)
int argc;
char **argv;
{
    GtkApplication *app = gtk_application_new("com.unluckystrike.SwingChart", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}