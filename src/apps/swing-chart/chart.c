#include "chart.h"
#include <gtk/gtk.h>
#include <cairo.h>
#include <stdlib.h>
#include <time.h>

void update_graph(graph)
GraphData *graph;
{
    // 그래프에 대해 랜덤 값 배열 생성
    for (int i = 0; i < graph->num_values; i++)
    {
        graph->values[i] = (double)(rand() % 101); // 0에서 100 사이의 랜덤 값
    }
}

void draw_graph(area, cr, width, height, graph)
GtkDrawingArea *area;
cairo_t *cr;
int width;
int height;
GraphData *graph;
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

    // 그래프 그리기
    double x_step = (double)width / (graph->num_values - 1);
    double y_scale = (double)(height - 20) / (graph->max_value - graph->min_value);

    cairo_set_source_rgb(cr, 0.2 + 0.2, 0.4, 0.8 - 0.2);
    cairo_set_line_width(cr, 3);
    
    for (int i = 0; i < graph->num_values; i++)
    {
        double x = i * x_step + 10;
        double y = height - ((graph->values[i] - graph->min_value) * y_scale) - 10;
        
        if (i == 0)
            cairo_move_to(cr, x, y);
        else
            cairo_line_to(cr, x, y);
    }
    
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 1, 0, 0);
    
    for (int i = 0; i < graph->num_values; i++)
    {
        double x = i * x_step + 10;
        double y = height - ((graph->values[i] - graph->min_value) * y_scale) - 10;
        
        cairo_arc(cr, x, y, 4, 0, 2 * 3.1416);
        cairo_fill(cr);
    }
}

void draw_graphs_idx(area, cr, width, height, graphs, idx)
GtkDrawingArea *area;
cairo_t *cr;
int width;
int height;
GraphData graphs[];
int idx;
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
    double x_step = (double)width / (graphs[idx].num_values - 1);
    double y_scale = (double)(height - 20) / (graphs[idx].max_value - graphs[idx].min_value);

    cairo_set_source_rgb(cr, 0.2 + 0.2 * idx, 0.4, 0.8 - 0.2 * idx);
    cairo_set_line_width(cr, 3);
    
    for (int i = 0; i < graphs[idx].num_values; i++)
    {
        double x = i * x_step + 10;
        double y = height - ((graphs[idx].values[i] - graphs[idx].min_value) * y_scale) - 10;
        
        if (i == 0)
            cairo_move_to(cr, x, y);
        else
            cairo_line_to(cr, x, y);
    }
    
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 1, 0, 0);
    
    for (int i = 0; i < graphs[idx].num_values; i++)
    {
        double x = i * x_step + 10;
        double y = height - ((graphs[idx].values[i] - graphs[idx].min_value) * y_scale) - 10;
        
        cairo_arc(cr, x, y, 4, 0, 2 * 3.1416);
        cairo_fill(cr);
    }
}