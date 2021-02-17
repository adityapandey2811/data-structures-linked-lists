#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *GoToKthNode(node *head,int k){
	node *temp = head;
	while(--k){
		if(temp==NULL)
			return NULL;
		if(temp->next == NULL)
			return temp;
		temp = temp->next;
	}
	return temp;	
}
void reverse(node **head){
	node *temp = *head,*new,*link = NULL;
	while(temp){
		new = temp->next;
		temp->next = link;
		link = temp;
		temp = new;
	}
}
void kreverse(node **head, int k){
	node *temp = *head,*prev = NULL,*new = temp->next,*spare1 = *head ,*spare2 = *head;
	int i,j,n,x,v;
	*head = GoToKthNode(*head,k);
	spare1 = *head;
	while(temp){
		new = spare1->next;
		spare1->next = NULL;
		reverse(&temp);
		if(prev != NULL){
			prev->next = spare1;
		}
		prev = temp;
		temp->next = new;
		spare1 = GoToKthNode(temp,k+1);
		if(spare1 == NULL)
			break;
		temp = temp->next;
	}
}
void main(){
	int i;
	node *head = NULL;
	for(i=9;i>0;i--){
		head = insertAtEnd(head);
	}
	printf("K: ");
	scanf("%d",&i);
	kreverse(&head,i);
	display(head);
}
