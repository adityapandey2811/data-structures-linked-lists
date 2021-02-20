#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *mergeSortedList(node *head1, node* head2){
   	node *temp1 = head1, *temp2 = head2, *spare = NULL, *new;
	spare = (node*)malloc(sizeof(node));
	new = spare;
   	while(temp1 != NULL && temp2 != NULL){
   		spare->next = temp1;
   		spare = spare->next;
   		temp1 = temp1->next;
   		spare->next = temp2;
   		spare = spare->next;
   		temp2 = temp2->next;
   	}
   	if(temp1 == NULL)
   		spare->next = temp2;
   	else
   		spare->next = temp1;
   	free(new);
   	return head1;
}
void main(){
    node *head = NULL,*head1 = NULL,*head2 = NULL;
    int i;
    for(i=10;i>0;i--){
        head1 = insertAtEnd(head1);
    }
    for(i=4;i>0;i--){
        head2 = insertAtEnd(head2);
    }
    head = mergeSortedList(head1,head2);
    display(head);
}