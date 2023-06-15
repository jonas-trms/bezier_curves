#include "bezier_computations.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// bezier computations
int binomial_coefficient(int k, int n) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  }

  else if (k == 0 || k == n) {
    return 1;
  }

  else {
    return binomial_coefficient(k - 1, n - 1) + binomial_coefficient(k, n - 1);
  }
}

double bernstein(int i, int n, double t) {
  int bin_coeff = binomial_coefficient(i, n);

  double a = pow(t, i);
  double b = pow((1. - t), n - i);

  return (double)bin_coeff * a * b;
}

long bezier_point_x(vertex_chain *vchain, double t) {
  int n = vchain->len;
  double res = 0.;

  vertex_node *curr = vchain->start;

  for (int i = 0; i < n; i++) {
    double ith_comp = bernstein(i, n - 1, t) * (double)((curr->v)->x);
    res += ith_comp;
    curr = curr->next;
  }

  return lround(res);
}

long bezier_point_y(vertex_chain *vchain, double t) {
  int n = vchain->len;
  double res = 0.;

  vertex_node *curr = vchain->start;

  for (int i = 0; i < n; i++) {
    double ith_comp = bernstein(i, n - 1, t) * (double)((curr->v)->y);
    res += ith_comp;
    curr = curr->next;
  }

  return lround(res);
}

void compute_bezier(long nb_points, int width, int height, int *canvas,
                    vertex_chain *points) {
  for (long i = 0; i < nb_points; i++) {
    double t = (double)i / ((double)(nb_points - 1));

    long x = bezier_point_x(points, t);
    long y = bezier_point_y(points, t);

    if (x >= width || y >= height) {
      printf("Error, computed point must be inside the defined canvas\n");
      return;
    }

    if (canvas[y * width + x] == 1 || canvas[y * width + x] == 3) {
      canvas[y * width + x] = 3;
    }

    else {
      canvas[y * width + x] = 2;
    }
  }
}