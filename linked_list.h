#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;
#ifndef LINKED_LIST_CONSTANTS
#define LINKED_LIST_CONSTANTS
extern const unsigned int SIZEOF_LinkedList;
#endif

// getters
void *get_data_linked_list(LinkedList *node);
LinkedList *get_next_linked_list(LinkedList *node);
// methods
void add_linked_list(LinkedList **phead, void *data);
void delete_n_linked_list(LinkedList **phead, int n);
void free_linked_list(LinkedList **phead);
void print_linked_list(LinkedList *node, char *data_type);
LinkedList *create_from_data_linked_list(void *data);
LinkedList *find_by_value_linked_list(LinkedList *head, void *value);
