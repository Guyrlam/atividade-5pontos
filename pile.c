#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Pile;

Pile create_pile()
{
    Pile p;
    p.top = NULL;

    return p;
};

void push_pile(Pile *p, int x)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }
    new_node->value = x;
    new_node->next = p->top;
    p->top = new_node;
}

int release_pile(Pile *p)
{
    if (p->top == NULL)
    {
        return 1;
    }
    int value = p->top->value;
    Node *new_top = p->top->next;
    free(p->top);
    p->top = new_top;

    return value;
}