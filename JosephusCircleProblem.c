#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void getM(node **head, int m){
	node *temp = *head,*prev = NULL;
	while(--m){
		prev = temp;
		temp = temp->next;
	}
	if(*head == temp){
		*head = temp->next;
	}
	prev->next = temp->next;
	*head = prev->next;
	free(temp);
}
void findLeader(node **head, int m){
	node *temp = *head,*current = *head,*prev = NULL,*spare = NULL;
	while(temp->next != temp){
		getM(&temp,m);
	}
	printf("%d\n",temp->data);
	return;
}
void main(){
	int i;
	node *head = NULL,*temp;
	for(i=5;i>0;i--){
		head = insertAtEnd(head);
	}
	temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = head;
	printf("M: ");
	scanf("%d",&i);
	findLeader(&head,i);
}
