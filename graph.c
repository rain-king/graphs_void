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
	char *spaces = malloc(depth+1);
	for (int i=0; i<depth; i++) spaces[i] = ' ';
	spaces[depth] = '\0';
	printf("%s%d\n", spaces, node->data);
	free(spaces);

	if (llvisited == NULL) {
		llvisited = malloc(SIZEOF_LinkedList);
	}
	add_linked_list(&llvisited, (void *)node);

	LinkedList *curr_in_node_adjacent = node->adjacent;
	while (curr_in_node_adjacent != NULL) {
		LinkedList *curr_visited = llvisited;
		bool visited = false;
		while (curr_visited != NULL) {
			visited |= (get_data_linked_list(curr_in_node_adjacent) == get_data_linked_list(curr_visited));
			curr_visited = get_next_linked_list(curr_visited);
		}
		if (!visited) {
			Graph *next = (Graph *)get_data_linked_list(curr_in_node_adjacent);
			traverse_graph(next, llvisited, depth+1);
		}
		curr_in_node_adjacent = get_next_linked_list(curr_in_node_adjacent);
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
	add_linked_list(&llvisited, (void *)node);

	LinkedList *curr_in_node_adjacent = node->adjacent;
	while (curr_in_node_adjacent != NULL) {
		LinkedList *curr_visited = llvisited;
		bool visited = false;
		while (curr_visited != NULL) {
			visited |= (get_data_linked_list(curr_in_node_adjacent) == get_data_linked_list(curr_visited));
			curr_visited = get_next_linked_list(curr_visited);
		}
		if (!visited) {
			Graph *next = (Graph *)get_data_linked_list(curr_in_node_adjacent);
			free_graph(&next, llvisited);
		}
		curr_in_node_adjacent = get_next_linked_list(curr_in_node_adjacent);
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
	const char* function_name_str = "construct_graph";
	printf("%s: Enter the integer data for this node:\n", function_name_str);
	int data;
	scanf("%d", &data); printf("%s: %d\n", function_name_str, data);
	Graph *node = create_from_data_graph(data);
	if (llcreated_nodes == NULL) {
		llcreated_nodes = malloc(SIZEOF_LinkedList);
	}
	add_linked_list(&llcreated_nodes, (void *)node);
	while (true) {
		int add_child;
		printf("%s: Add a child for this node (data %d)? 0 for no, 1 for yes:\n", function_name_str, node->data);
		scanf("%d", &add_child); printf("%s: %d\n", function_name_str, add_child);
		if (!add_child) {
			break;
		}
		printf("%s: Select from existing (0) or create new node (1)?\n", function_name_str);
		int create_new_node;
		scanf("%d", &create_new_node); printf("%s: %d\n", function_name_str, create_new_node);
		if (create_new_node) {
			add_edge_graph(node, construct_graph(llcreated_nodes));
		} else {
			LinkedList *curr = llcreated_nodes;
			printf("%s: Existing node data:\n", function_name_str);
			bool found_existing_nodes = false;
			while (curr != NULL) {
				Graph *current_graph = (Graph *)get_data_linked_list(curr);
				if (current_graph != NULL) {
					printf("%s: %d ", get_data_graph(current_graph));
					found_existing_nodes = true;
				}
				curr = get_next_linked_list(curr);
			}
			if (found_existing_nodes) printf("\n");
			printf("%s: Select a value, to add the respective node as a child:\n", function_name_str);
			int value;
			scanf("%d", &value); printf("%s: %d\n", function_name_str, value);
			Graph *found_node = find_by_value_graph(llcreated_nodes, value);
			if (found_node != NULL) {
				add_edge_graph(node, found_node);
			}
		}
	}
	return node;
}

Graph *find_by_value_graph(LinkedList *graph_nodes, int value) {
	const char *function_name_str = "find_by_value_graph";
	printf("%s: Searching %d\n", function_name_str, value);
	if (graph_nodes == NULL) {
		printf("%s: Got NULL list\n", function_name_str);
		return NULL;
	}
	LinkedList *curr = graph_nodes;
	while (curr != NULL) {
		Graph *current_graph_node = (Graph *)get_data_linked_list(curr);
		int current_value;
		if (current_graph_node != NULL) {
			printf("%s: Got non-NULL Graph node\n", function_name_str);
			current_value = get_data_graph(current_graph_node);
		} else {
			printf("%s: Got NULL graph node\n", function_name_str);
			curr = get_next_linked_list(curr);
			continue;
		}
		if (value == current_value)
			return current_graph_node;
		curr = get_next_linked_list(curr);
	}
	printf("%s: Value not found\n", function_name_str);
	return NULL;
}

Graph *create_from_data_graph(int data) {
	Graph *node = malloc(sizeof(Graph));
	node->data = data;
	node->adjacent = NULL;
	return node;
}

void add_edge_graph(Graph *tail, Graph *head) {
	const char *function_name_str = "add_edge_graph";
	bool null_head = (head == NULL);
	bool null_tail = (tail == NULL);
	if (null_head) {
		printf("%s: Tried to add null graph to tail, not adding\n", function_name_str);
	}
	if (null_tail) {
		printf("%s: Tried to add a graph to a null tail\n", function_name_str);
	}
	if (null_head || null_tail) return;
	printf("%s: Trying to add edge (%d, %d)\n", function_name_str, tail->data, head->data);
	add_linked_list(&(tail->adjacent), (void *)head);
	printf("%s: Done\n", function_name_str);
}

// void print_adjacent_graph(Graph *node) {
// 	print_linked_list(node->adjacent);
// }

LinkedList *get_adjacent_graph(Graph *node) {
	return node->adjacent;
}

int get_data_graph(Graph *node) {
	return node->data;
}

// void traverse_graph(Graph **phead);
