#include "linked_list.h"

typedef struct LinkedList {
	struct LinkedList *next;
	void *data;
} LinkedList;

const unsigned int SIZEOF_LinkedList = sizeof(LinkedList);

void add_linked_list(LinkedList **phead, void *data) {
	LinkedList *new_node = create_from_data_linked_list(data);
	if (*phead == NULL) {
		*phead = new_node;
		return;
	}

	LinkedList *curr = *phead;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_node;
}

void delete_n_linked_list(LinkedList **phead, int n) {
	if (*phead == NULL) return;
	LinkedList *curr = *phead;
	for (int i=0; i<n; i++) {
		if (curr == NULL) break;
		LinkedList *next = curr->next;
		free(curr->data);
		free(curr);
		curr = next;
	}
	*phead = curr;
}

void free_linked_list(LinkedList **phead) {
	if (*phead == NULL) return;
	LinkedList *curr = *phead;
	while (curr != NULL) {
		LinkedList *next = curr->next;
		free(curr->data);
		free(curr);
		curr = next;
	}
	*phead = NULL;
}

void print_linked_list(LinkedList *head, char *type) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	LinkedList *curr = head;
	while (curr != NULL) {
		if (curr->data == NULL) {
			curr = curr->next;
			continue;
		}
		if (strcmp(type, "d")) {
			printf("%d\n", *(int *)(curr->data));
		} else if (strcmp(type, "f")) {
			printf("%f\n", *(float *)(curr->data));
		} else if (strcmp(type, "s")) {
			printf("%s\n", (char *)(curr->data));
		} else if (strcmp(type, "c")) {
			printf("%c\n", *(char *)(curr->data));
		}
		curr = curr->next;
	}
}

void *get_data_linked_list(LinkedList *node) {
	return node == NULL ? NULL : node->data;
}

LinkedList *next_linked_list(LinkedList *node) {
    return node->next;
}

LinkedList *create_from_data_linked_list(void *data) {
	LinkedList *node = malloc(SIZEOF_LinkedList);
	node->data = data;
	node->next = NULL;
	return node;
}

LinkedList *find_by_value_linked_list(LinkedList *head, void *value) {
	LinkedList *curr = head;
	while (curr != NULL) {
		if (curr->data == value) return curr;
		curr = curr->next;
	}
	return NULL;
}
