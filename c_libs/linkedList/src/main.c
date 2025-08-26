#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

void printLinkedList(linked_list *list);

int main(int argc, char *argv[])
{
    linked_list list1 = make_list();

    list_push_tail(&list1, 4);
    list_push_tail(&list1, 5);
    list_push_head(&list1, 3);
    list_push_head(&list1, 2);
    list_push_head(&list1, 1);

    printLinkedList(&list1);

    printf("%d \n", list_pop_tail(&list1));
    printf("%d \n", list_pop_head(&list1));

    printLinkedList(&list1);

    list_insert(&list1, 3, 10);
    list_remove(&list1, 4);

    printLinkedList(&list1);

    printf("%d \n", list_get(&list1, 2));

    delete_list(&list1);

    return 0;
}

void printLinkedList(linked_list *list)
{
    node *item = list->head;
    while (item)
    {
        printf("%d  ", item->data);
        item = item->next;
    }
    printf("\n");
}