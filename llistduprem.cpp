#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node* insert(int data,struct node *head){

	struct node *newnode = (struct node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;

	if(head==NULL){
		return newnode;
	}

	struct node *temp = head;

	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = newnode;

	return head;
}

