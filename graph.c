#include "graph.h"
// #define DEBUG
typedef struct Graph {
	int data;
	LinkedList *adjacent;
} Graph;
unsigned int SIZEOF_Graph = sizeof(Graph);

void traverse_graph(Graph *node, LinkedList *llvisited, int depth) {
	if (node == NULL) {
		return;
	}
	char spaces[depth+1];
	for (int i=0; i<depth; i++) spaces[i] = ' ';
	spaces[depth] = '\0';
	printf("%s%d\n", spaces, node->data);

	if (llvisited == NULL) {
		llvisited = malloc(SIZEOF_LinkedList);
	}
	LinkedList *ll_node = create_from_data_linked_list((void *)node);
	add_linked_list(&llvisited, ll_node);

	LinkedList *curr_in_node_adjacent = node->adjacent;
	while (curr_in_node_adjacent != NULL) {
		LinkedList *curr_visited = llvisited;
		bool visited = false;
		while (curr_visited != NULL) {
			visited |= (get_data_linked_list(curr_in_node_adjacent) == get_data_linked_list(curr_visited));
			curr_visited = next_linked_list(curr_visited);
		}
		if (!visited) {
			Graph *next = (Graph *)get_data_linked_list(curr_in_node_adjacent);
			traverse_graph(next, llvisited, depth+1);
		}
		curr_in_node_adjacent = next_linked_list(curr_in_node_adjacent);
	}
}

void free_graph(Graph **pnode, LinkedList *llvisited) {
	Graph *node = *pnode;
	if (node == NULL) {
		return;
	}

	if (llvisited == NULL) {
		llvisited = malloc(SIZEOF_LinkedList);
	}
	LinkedList *ll_node = create_from_data_linked_list((void *)node);
	add_linked_list(&llvisited, ll_node);

	LinkedList *curr_in_node_adjacent = node->adjacent;
	while (curr_in_node_adjacent != NULL) {
		LinkedList *curr_visited = llvisited;
		bool visited = false;
		while (curr_visited != NULL) {
			visited |= (get_data_linked_list(curr_in_node_adjacent) == get_data_linked_list(curr_visited));
			curr_visited = next_linked_list(curr_visited);
		}
		if (!visited) {
			Graph *next = (Graph *)get_data_linked_list(curr_in_node_adjacent);
			free_graph(&next, llvisited);
		}
		curr_in_node_adjacent = next_linked_list(curr_in_node_adjacent);
	}
	free(node);
}

Graph *construct_tree_graph() {
	int data;
	printf("Enter the integer data for this node:\n");
	scanf("%d", &data);
	Graph *node = create_from_data_graph(data);
	while (true) {
		int add_child;
		printf("Add a child for this node (data %d)? 0 for no, 1 for yes:\n", node->data);
		scanf("%d", &add_child);
		if (!add_child) {
			break;
		}
		add_edge_graph(node, construct_tree_graph());
	}
	return node;
}

Graph *construct_graph(LinkedList *llcreated_nodes) {
	printf("Enter the integer data for this node:\n");
	int data;
	scanf("%d", &data); printf("%d\n", data);
	Graph *node = create_from_data_graph(data);
	if (llcreated_nodes == NULL) {
		llcreated_nodes = malloc(SIZEOF_LinkedList);
	}
	LinkedList *last_created = create_from_data_linked_list((void *) node);
	add_linked_list(&llcreated_nodes, last_created);
	while (true) {
		int add_child;
		printf("Add a child for this node (data %d)? 0 for no, 1 for yes:\n", node->data);
		scanf("%d", &add_child); printf("%d\n", add_child);
		if (!add_child) {
			break;
		}
		printf("Select from existing (0) or create new node (1)?\n");
		int create_new_node;
		scanf("%d", &create_new_node); printf("%d\n", create_new_node);
		if (create_new_node) {
			add_edge_graph(node, construct_graph(llcreated_nodes));
		} else {
			LinkedList *curr = llcreated_nodes;
			printf("Existing node data:\n");
			while (curr != NULL) {
				Graph *current_graph = (Graph *) get_data_linked_list(curr);
				if (current_graph != NULL)
					printf("%d ", get_data_graph(current_graph));
				curr = next_linked_list(curr);
			}
			printf("\nSelect a value, to add the respective node as a child:\n");
			int value;
			scanf("%d", &value); printf("%d\n", value);
			Graph *found_node = find_by_value_graph(llcreated_nodes, value);
			if (found_node != NULL) {
				add_edge_graph(node, found_node);
			} else {
				printf("Node not found by value %d\n", value);
			}
		}
	}
	return node;
}

Graph *find_by_value_graph(LinkedList *graph_nodes, int value) {
	if (graph_nodes == NULL) {
		printf("Tried to find %d in NULL list\n", value);
		return NULL;
	}
	LinkedList *curr = graph_nodes;
	while (curr != NULL) {
		Graph *current_graph_node = (Graph *) get_data_linked_list(curr);
		printf("Got graph from linked list\n");
		int current_value;
		if (current_graph_node != NULL) {
			current_value = get_data_graph(current_graph_node);
		} else {
			printf("Null graph node\n");
			curr = next_linked_list(curr);
			continue;
		}
		if (value == current_value)
			return current_graph_node;
		curr = next_linked_list(curr);
	}
	printf("Value %d not found in graph list", value);
	return NULL;
}

int get_data_graph(Graph *node) {
	return node->data;
}

Graph *create_from_data_graph(int data) {
	Graph *node = malloc(sizeof(Graph));
	node->data = data;
	node->adjacent = NULL;
	return node;
}

void add_edge_graph(Graph *tail, Graph *head) {
	if (head == NULL) {
		printf("Tried to add null graph to tail with data %d\n", tail->data);
		return;
	}
	LinkedList *head_llnode = create_from_data_linked_list((void *) head);
	add_linked_list(&(tail->adjacent), head_llnode);
}

void print_adjacent_graph(Graph *node) {
	print_linked_list_int(node->adjacent);
}

LinkedList *get_adjacent_graph(Graph *node) {
	return node->adjacent;
}


// void traverse_graph(Graph **phead);
