#include "linked_list.h"

int main() {
    int integer_numbers[10];
    for (int i=0; i<10; i++) integer_numbers[i] = i; 
    LinkedList *head = malloc(SIZEOF_LinkedList);
    add_linked_list(&head, (void *)&);
    print_linked_list(head, "d");
    free_linked_list(&head);
}