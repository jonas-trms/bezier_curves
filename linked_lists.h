#ifndef LINKED_LISTS
#define LINKED_LISTS

struct vertex {
  long x;
  long y;
};

typedef struct vertex vertex;

struct vertex_node {
  struct vertex *v;
  struct vertex_node *next;
};

typedef struct vertex_node vertex_node;

struct vertex_chain {
  int len;
  vertex_node *start;
  vertex_node *end;
};

typedef struct vertex_chain vertex_chain;

vertex_chain *new_vchain(void);
void insert_vchain(vertex *v, vertex_chain *vchain);
void clear_v_chain(vertex_chain *vchain);

#endif