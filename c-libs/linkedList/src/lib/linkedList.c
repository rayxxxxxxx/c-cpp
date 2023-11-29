#include <error.h>
#include <errno.h>
#include <stdlib.h>

#include <stdio.h>

#include "linkedList.h"

node make_node(int value)
{
    node item;
    item.data = value;
    item.next = NULL;
    return item;
}

void delete_node(node *item)
{
    if (!item->next)
    {
        free(item);
        return;
    }
    delete_node(item->next);
    free(item);
}

node copy_node(node *item)
{
    node newitem;
    newitem.data = item->data;
    newitem.next = item->next;
    return newitem;
}

node node_set_next(node *item, node *next)
{
    item->next = next;
}

linked_list make_list()
{
    linked_list list;
    list.size = 0;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void delete_list(linked_list *list)
{
    delete_node(list->head);
}

int list_get(linked_list *list, size_t idx)
{
    if (idx >= list->size)
    {
        error(1, 1, "ivalid index");
    }

    node *c = list->head;

    for (size_t i = 0; i < idx; i++)
    {
        c = c->next;
    }

    return c->data;
}

void list_push_tail(linked_list *list, int value)
{
    node *item = (node *)malloc(sizeof(item));
    item->data = value;

    if (!(list->head))
    {
        list->head = item;
        list->tail = list->head;
        list->size++;
    }
    else
    {
        list->tail->next = item;
        list->tail = list->tail->next;
        list->size++;
    }
}

void list_push_head(linked_list *list, int value)
{
    node *item = (node *)malloc(sizeof(item));
    item->data = value;

    if (!(list->head))
    {
        list->head = item;
        list->tail = list->head;
        list->size++;
    }
    else
    {
        item->next = list->head;
        list->head = item;
        list->size++;
    }
}

int list_pop_tail(linked_list *list)
{
    node *c = list->head;

    for (size_t i = 0; i < list->size - 2; i++)
    {
        c = c->next;
    }

    int data = c->next->data;

    free(c->next);

    c->next = NULL;
    list->tail = c;
    list->size--;

    return data;
}

int list_pop_head(linked_list *list)
{
    int headData = list->head->data;
    node *headNext = list->head->next;

    free(list->head);

    list->head = headNext;
    list->size--;

    return headData;
}

void list_insert(linked_list *list, size_t idx, int value)
{
    if (idx < 0 || idx > list->size)
    {
        error(1, 1, "ivalid index");
    }

    if (idx == 0)
    {
        list_push_head(list, value);
    }
    else if (idx == list->size)
    {
        list_push_tail(list, value);
    }
    else
    {
        node *c = list->head;

        for (size_t i = 0; i < idx - 1; i++)
        {
            c = c->next;
        }

        node *item = (node *)malloc(sizeof(item));
        item->data = value;

        item->next = c->next;
        c->next = item;
        list->size++;
    }
}

int list_remove(linked_list *list, size_t idx)
{
    if (idx < 0 || idx > list->size)
    {
        error(1, 1, "ivalid index");
    }

    if (idx == 0)
    {
        return list_pop_head(list);
    }
    else if (idx == list->size)
    {
        return list_pop_tail(list);
    }
    else
    {
        node *c = list->head;

        for (size_t i = 0; i < idx - 1; i++)
        {
            c = c->next;
        }

        c->next = c->next->next;
        list->size--;
    }
}
