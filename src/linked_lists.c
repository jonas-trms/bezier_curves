#include "linked_lists.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// linked lists
vertex_chain *new_vchain(void) {
  vertex_chain *new = malloc(sizeof(vertex_chain));
  new->len = 0;
  new->start = NULL;
  new->end = NULL;

  return new;
}

void insert_vchain(vertex *v, vertex_chain *vchain) {
  // inserts at end
  vertex_node *new = malloc(sizeof(vertex_node));
  new->v = v;
  new->next = NULL;

  if (vchain->end == NULL) {
    vchain->start = new;
    vchain->end = new;
  }

  else {
    (vchain->end)->next = new;
    vchain->end = new;
  }

  (vchain->len)++;
}

void clear_v_chain(vertex_chain *vchain) {
  vertex_node *curr = vchain->start;

  while (curr != NULL && curr->next != NULL) {
    vertex_node *tmp = curr;
    curr = curr->next;
    free(tmp->v);
    free(tmp);
  }

  if (curr != NULL) {
    free(curr->v);
    free(curr);
  }

  vchain->len = 0;
  vchain->start = NULL;
  vchain->end = NULL;
}