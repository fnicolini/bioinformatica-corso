#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;
Node* createList(unsigned int content);
void printList(Node *head);
void insert(unsigned int content, Node *head);


#endif