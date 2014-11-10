#include <stdio.h>

const int NODE_COUNT = 10;

void print_nodes(int *nodes, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", *nodes);
    nodes++;
  }
  printf("\n");
}

void initialize_nodes(int *nodes, int size) {
  for(int i = 0; i < size; i++) {
    *nodes = i;
    nodes++;
  }
}

/*
 * Find ID in p, and assign q to all matching values
 */
void _union(int p, int q, int *nodes, int size) {
  int pid = nodes[p];
  int qid = nodes[q];

  printf("Union P(%d,%d) Q(%d,%d) ", p, pid, q, qid);
  
  for(int i = 0; i < size; i++) {
    if(*(nodes + i) == pid) {
      *(nodes + i) = qid;
    }
  }

  print_nodes(nodes, size);

}

int main(void) {
  int nodes[10];
  printf("Node count: %d\n", NODE_COUNT);

  initialize_nodes(nodes, NODE_COUNT);
  print_nodes(nodes, NODE_COUNT);

  _union(3, 4, nodes, NODE_COUNT);

  return 0;
}
