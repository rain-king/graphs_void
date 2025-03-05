#include "linked_list.h"

typedef struct Graph Graph;
#ifndef GRAPH_CONSTANTS
#define GRAPH_CONSTANTS
extern unsigned int SIZEOF_Graph;
#endif

Graph *create_from_data_graph(int data);
void add_edge_graph(Graph *pnode1, Graph *pnode2);
void traverse_graph(Graph *node, LinkedList *llvisited, int depth);
// void print_adjacent_graph(Graph *node);
Graph *construct_tree_graph();
Graph *construct_graph(LinkedList *llcreated_nodes);
Graph *find_by_value_graph(LinkedList *graph_nodes, int value);
LinkedList *get_adj_list_graph(Graph *node);
int get_data_graph(Graph *node);
void free_graph(Graph **pnode, LinkedList *llvisited);
