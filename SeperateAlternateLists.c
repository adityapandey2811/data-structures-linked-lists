#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* seperateLists(node **head){
	node *temp1 , *temp2, *spare = *head, *rnode;
	if(spare == NULL || spare->next == NULL)
		return NULL;
	temp1 = *head;
	temp2 = temp1->next;
	rnode = temp2;
	spare = spare->next->next;
	while(spare){
		temp1->next = spare;
		temp1 = temp1->next;
		spare = spare->next;
		temp2->next = spare;
		temp2 = temp2->next;
		spare = spare->next;
	}
	temp1->next = NULL;
	temp2->next = NULL;
	return rnode;
}
void main(){
	int i;
	node *head1 = NULL, *head2 = NULL;
	for(i=0;i<10;i++)
		head1 = insertAtEnd(head1);
	head2 = seperateLists(&head1);
	display(head1);
	display(head2);
}