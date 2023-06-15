#include "bezier_computations.h"
#include "canvas_operations.h"
#include "linked_lists.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// output
void write_output(char *path, long width, long height, int *canvas) {
  FILE *output = fopen(path, "w");

  fprintf(output, "P3\n%ld %ld\n255\n", width, height);
  for (long j = 0; j < height; j++) {
    for (long i = 0; i < width; i++) {
      if (canvas[j * width + i] == 0) {
        fprintf(output, "0 0 0");
      } else if (canvas[j * width + i] == 1) {
        fprintf(output, "255 0 0");
      }

      else if (canvas[j * width + i] == 2) {
        fprintf(output, "0 255 0");
      }

      else if (canvas[j * width + i] == 3) {
        fprintf(output, "0 0 255");
      }

      else {
        printf("Error, unexpected value\n");
        return;
      }

      fprintf(output, "\n");
    }
  }

  fclose(output);
}

int main(int argc, char *argv[]) {
  long width;
  long height;
  char *output = argv[1];

  char *buffer;
  size_t bufsize = 500;

  printf("Please choose width & height\n");

  int stay = 1;

  while (stay == 1) {
    while (getline(&buffer, &bufsize, stdin) == 0) {
    }

    int read = sscanf(buffer, "%ld %ld", &width, &height);

    if (read != 2) {
      printf("Bad syntax\n");
    }

    else {
      stay = 0;
    }
  }

  int *canvas = malloc(width * height * sizeof(int));
  vertex_chain *points = new_vchain();
  clear_canvas(width, height, canvas);
  write_output(output, width, height, canvas);
  // 0 is top left
  // cases:
  // 0: nothing, black 0 0 0
  // 1: point, red 255 0 0
  // 2: curve, green 0 255 0
  // 3: point & curve, blue 0 0 255

  while (1 == 1) {
    while (getline(&buffer, &bufsize, stdin) == 0) {
    }

    if (buffer[0] == 'q') {
      clear_v_chain(points);
      free(points);
      free(canvas);

      return 0;
    }

    else if (buffer[0] == 'a') {
      double x;
      double y;
      int read = sscanf(buffer, "add %lf %lf", &x, &y);

      if (read != 2) {
        printf("Bad syntax\n");
      }

      else {
        if (x > 1. || x < 0. || y > 1. || y < 0.) {
          printf("Error: x and y must belong to [0,1]\n");
        } else {
          int x_int = lround((double)(width - 1) * x);
          int y_int = lround((double)(height - 1) * y);
          add_point(x_int, y_int, width, height, canvas, points);
          write_output(output, width, height, canvas);
        }
      }
    }

    else if (buffer[0] == 'g') {
      long n;
      int read = sscanf(buffer, "generate %ld", &n);

      if (read != 1) {
        printf("Bad syntax\n");
      }

      else {
        clear_curves(width, height, canvas);
        compute_bezier(n, width, height, canvas, points);
        write_output(output, width, height, canvas);
      }
    }

    else if (buffer[0] == 'b') {
      clear_v_chain(points);
      clear_canvas(width, height, canvas);
      write_output(output, width, height, canvas);
    }

    else {
      printf("Unknown command\n");
    }
  }
}