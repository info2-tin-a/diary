#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} List;

void push(List *list, int value) {
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    *node = (Node){.value = value, .next = NULL};
    if (list->tail != NULL)
        list->tail->next = node;
    if (list->head == NULL)
        list->head = node;
    list->tail = node;
}

int shift(List *list) {
    Node *node = list->head;
    int value = node->value;
    list->head = node->next;
    free(node);
    return value;
}

void display(List *list)
{
    Node *walk = list->head;
    while(walk != NULL) {
        printf("%d ", walk->value);
        walk = walk->next;
    }
}

int main()
{
    List list = {.head=NULL, .tail=NULL};
    push(&list, 4);
    push(&list, 8);
    push(&list, 15);
    push(&list, 16);
    push(&list, 23);
    push(&list, 42);

    display(&list);
    int v = shift(&list);
    printf("L'élément %d à été retiré\n", v);
    display(&list);
}