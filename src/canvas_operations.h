#ifndef CANVAS_OPERATIONS
#define CANVAS_OPERATIONS
#include "linked_lists.h"

void clear_canvas(int width, int height, int *canvas);
void clear_curves(int width, int height, int *canvas);
void add_point(long x, long y, long width, long height, int *canvas,
               vertex_chain *points);

#endif