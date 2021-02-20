//Aditya’s code to merge sorted lists
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Merging
node* mergeSortedList(node *head1, node *head2){
	node *temp1 = head1, *temp2 = head2, *spare, *head;
	head = (node*)malloc(sizeof(node));
	spare = head;
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->data>=temp2->data){
			spare->next = temp2;
			temp2 = temp2->next;
		}
		else{
			spare->next = temp1;
			temp1 = temp1->next;
		}
		spare = spare->next;
	}
	if(temp1 == NULL)
		spare->next = temp2;
	else
		spare->next = temp1;
	spare = head->next;
	free(head);
	return spare;
}
//Main function
void main(){
    node *head = NULL,*head1 = NULL,*head2 = NULL;
    int i;
//List Creation
    for(i=4;i>0;i--){
        head1 = insertAtEnd(head1);
    }
    for(i=5;i>0;i--){
        head2 = insertAtEnd(head2);
    }
//Storing merged list in head
    head = mergeSortedList(head1,head2);
    display(head);
}

