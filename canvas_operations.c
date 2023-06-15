#include "canvas_operations.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// canvas operations
void clear_canvas(int width, int height, int *canvas) {
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      canvas[j * width + i] = 0;
    }
  }
}

void clear_curves(int width, int height, int *canvas) {
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if (canvas[j * width + i] == 3) {
        canvas[j * width + i] = 1;
      }

      else if (canvas[j * width + i] == 2) {
        canvas[j * width + i] = 0;
      }
    }
  }
}

void add_point(long x, long y, long width, long height, int *canvas,
               vertex_chain *points) {
  if (x >= width || y >= height) {
    printf("Error, point must be inside the defined canvas\n");
    return;
  }

  else {
    vertex *new = malloc(sizeof(vertex));
    new->x = x;
    new->y = y;

    insert_vchain(new, points);

    if (canvas[y * width + x] == 2 || canvas[y * width + x] == 3) {
      canvas[y * width + x] = 3;
    }

    else {
      canvas[y * width + x] = 1;
    }
  }
}