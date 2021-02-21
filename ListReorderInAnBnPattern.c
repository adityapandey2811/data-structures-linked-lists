#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void listReorder(node **head){
	node *temp = *head, *spare = NULL, *link = *head, *new = NULL;
	while(temp && temp->next){
		spare = link;
		link = link->next;
		if(temp->next!=NULL)
			temp = temp->next->next;
	}
	spare->next = NULL;
	temp = *head;
	spare = temp;
	temp = temp->next;
	while(temp || link){
		if(link!=NULL){
			spare->next = link;
			link = link->next;
			spare = spare->next;
		}
		if(temp!=NULL){
			spare->next = temp;
			temp = temp->next;
			spare = spare->next;
		}
	}
}
void main(){
	int i;
	node *head = NULL;
	for(i=0;i<10;i++){
		head = insertAtEnd(head);
	}
	listReorder(&head);
	display(head);
}