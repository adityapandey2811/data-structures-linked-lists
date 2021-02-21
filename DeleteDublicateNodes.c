#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void deleteDublicate(node **head){
	node *temp = *head, *new, *link;
	while(temp && temp->next){
		if(temp->data == temp->next->data){
			new = temp->next;
			temp->next = new->next;
			free(new);
		}
		else
			temp = temp->next;
	}
}
void main(){
	int i;
	node *head = NULL;
	for(i=0;i<10;i++){
		head = insertAtEnd(head);
	}
	deleteDublicate(&head);
	display(head);
}