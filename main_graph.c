#include "graph.h"

int main() {
	// Graph *node = create_from_data_graph(0b1101);
	// free(node);
	// printf("%d\n", SIZEOF_Graph);
	// Graph *head = construct_tree_graph();
	// LinkedList *empty = (LinkedList *) malloc(SIZEOF_LinkedList);
	Graph *head = construct_graph(NULL);
	// free(empty);
	// empty = malloc(SIZEOF_LinkedList);
	// // free_graph(&head, NULL);
	int starting_graph_data = 3;
	// printf("Selecciona el nodo para empezar a imprimir\n");
	// scanf("%d", &starting_graph_data);
	Graph *other_node = find_by_value_graph(get_adjacent_graph(head), starting_graph_data);
	// add_edge_graph(other_node, head);
	traverse_graph(other_node, NULL, 0);

	// int x[3] = { 1, 2, 3 };
	// LinkedList *list = malloc(SIZEOF_LinkedList);
	// add_linked_list(&list, create_from_data_linked_list(-1));
	// add_linked_list(&list, create_from_data_linked_list(-2));
	// add_linked_list(&list, create_from_data_linked_list(-3));
	// LinkedList *found = find_by_value_linked_list(list, -2);
	// printf("%d\n", (int)get_data_linked_list(found));
	printf("\n-------\n---0---\n-------\n");
}
