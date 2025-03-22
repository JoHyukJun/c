#include "chart.h"
#include <gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <time.h>

void update_graphs(graphs, num_graphs)
GraphData graphs[];
int num_graphs;
{
    // 랜덤 값을 생성하기 위해 시드 설정
    srand(time(NULL));

    // 각 그래프에 대해 랜덤 값 배열 생성
    for (int j = 0; j < num_graphs; j++)
    {
        for (int i = 0; i < graphs[j].num_values; i++)
        {
            graphs[j].values[i] = (double)(rand() % 101); // 0에서 100 사이의 랜덤 값
        }
    }
}

void draw_graphs(area, cr, width, height, graphs, num_graphs)
GtkDrawingArea *area;
cairo_t *cr;
int width;
int height;
GraphData graphs[];
int num_graphs;
{
    (void)area;

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 2);
    
    cairo_move_to(cr, 0, height - 10);
    cairo_line_to(cr, width, height - 10);
    
    cairo_move_to(cr, 10, 0);
    cairo_line_to(cr, 10, height);
    
    cairo_stroke(cr);

    // x축 값 표시
    for (int i = 0; i < NUM_VALUES; i += 10)
    {
        double x = i * (double)width / (NUM_VALUES - 1);
        cairo_move_to(cr, x, height - 5);
        cairo_show_text(cr, g_strdup_printf("%d", i));
    }

    // y축 값 표시
    for (int i = 0; i <= 100; i += 20)
    {
        double y = height - (i * (double)(height - 20) / 100);
        cairo_move_to(cr, 15, y);
        cairo_show_text(cr, g_strdup_printf("%d", i));
    }

    // 각 그래프 그리기
    for (int j = 0; j < num_graphs; j++)
    {
        double x_step = (double)width / (graphs[j].num_values - 1);
        double y_scale = (double)(height - 20) / (graphs[j].max_value - graphs[j].min_value);

        cairo_set_source_rgb(cr, 0.2 + 0.2 * j, 0.4, 0.8 - 0.2 * j);
        cairo_set_line_width(cr, 3);
        
        for (int i = 0; i < graphs[j].num_values; i++)
        {
            double x = i * x_step + 10;
            double y = height - ((graphs[j].values[i] - graphs[j].min_value) * y_scale) - 10;
            
            if (i == 0)
                cairo_move_to(cr, x, y);
            else
                cairo_line_to(cr, x, y);
        }
        
        cairo_stroke(cr);

        cairo_set_source_rgb(cr, 1, 0, 0);
        
        for (int i = 0; i < graphs[j].num_values; i++)
        {
            double x = i * x_step + 10;
            double y = height - ((graphs[j].values[i] - graphs[j].min_value) * y_scale) - 10;
            
            cairo_arc(cr, x, y, 4, 0, 2 * 3.1416);
            cairo_fill(cr);
        }
    }
}