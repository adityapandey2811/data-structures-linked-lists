#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *findCommon(node *head1, node *head2){
	node *tail = NULL, *new, *head = NULL, *temp;
	while(head1 && head2){
		if(head1->data == head2->data){
			temp = (node*)malloc(sizeof(node));
			temp->next = NULL;
			temp->data = head1->data;
			if(head == NULL){
				tail = head = temp;
			}
			else{
				tail->next = temp;
				tail = tail->next;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->data > head2->data)
			head2 = head2->next;
		else
			head1 = head1->next;
	}
	return head;
}
void main(){
	int i;
	node *head1 = NULL, *head2 = NULL, *head = NULL;
	for(i=0;i<6;i++){
		head1 = insertAtEnd(head1);
	}
	for(i=0;i<2;i++){
		head2 = insertAtEnd(head2);
	}
	head = findCommon(head1,head2);
	display(head);
}