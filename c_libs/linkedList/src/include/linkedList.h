#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linked_list
{
    size_t size;
    node *head;
    node *tail;
} linked_list;

node make_node(int value);
node copy_node(node *item);
void delete_node(node *item);

node node_set_next(node *item, node *next);

linked_list make_list();
void delete_list(linked_list *list);

int list_get(linked_list *list, size_t idx);

void list_push_tail(linked_list *list, int value);
void list_push_head(linked_list *list, int value);

int list_pop_tail(linked_list *list);
int list_pop_head(linked_list *list);

void list_insert(linked_list *list, size_t idx, int value);
int list_remove(linked_list *list, size_t idx);

#endif