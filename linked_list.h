#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;
#ifndef LINKED_LIST_CONSTANTS
#define LINKED_LIST_CONSTANTS
extern const unsigned int SIZEOF_LinkedList;
#endif

void add_linked_list(LinkedList **phead, LinkedList *child);
void delete_n_linked_list(LinkedList **phead, int n);
void free_linked_list(LinkedList **phead);
void print_linked_list_int(LinkedList *node);
void *get_data_linked_list(LinkedList *node);
LinkedList *next_linked_list(LinkedList *node);
LinkedList *create_from_data_linked_list(void *data);
LinkedList *find_by_value_linked_list(LinkedList *head, void *value);
