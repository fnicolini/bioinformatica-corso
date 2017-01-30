#include "linkedlist.h"

struct node {
	unsigned int data;
	struct node *next;
};

//display the list

Node* createList(unsigned int content){

	Node *head = (Node*)malloc(sizeof(Node));
	head -> data = content;
	head -> next = 0;

	return head;

}

void printList(Node *head) {
	printf("[ ");

	Node *current = head;

	while(current != 0) {
		printf("%d ", current -> data);
		current = current -> next;
	}

	printf("]\n");
}

void insert(unsigned int content, Node *head) {
	Node *to_add = (Node*)malloc(sizeof(Node));
	to_add -> data = content;
	to_add -> next = 0;

	Node *current = head;

	while(current -> next != 0){
		current = current -> next;
	}

	current -> next = to_add;

}