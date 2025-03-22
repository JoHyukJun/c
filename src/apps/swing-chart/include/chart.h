#ifndef __CHART_H__
#define __CHART_H__

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <cairo.h>

#define NUM_GRAPHS 1
#define NUM_CHARTS 12
#define NUM_VALUES 100

typedef struct
{
    double values[NUM_VALUES];
    int num_values;
    double max_value;
    double min_value;
} GraphData;
#define SZ_GRAPH_DATA sizeof(GraphData)

int init_graph_data(GraphData *data);
void update_graphs(GraphData graphs[], int num_graphs);
void draw_graphs(GtkDrawingArea *area, cairo_t *cr, int width, int height, GraphData graphs[], int num_graphs);

#endif // __CHART_H__
