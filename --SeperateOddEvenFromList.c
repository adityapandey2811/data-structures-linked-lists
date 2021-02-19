#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void seperateEven(node **head){
	node *temp = *head,*link = NULL,*spare = NULL,*even,*odd;
	while(temp){
		if(temp->data%2==0){
			if(link == NULL){
				link = temp;
			}
			else{
				even->next = temp;
			}
			even = temp;
		}
		else{
			if(spare == NULL){
				spare = temp;
			}
			else{
				odd->next = temp;
			}
			odd = temp;
		}
		temp = temp->next;
	}
	even->next = spare;
	odd->next = NULL;
    *head = link;
}
void main(){
	int i;
	node *head = NULL;
	for(i=0;i<12;i++){
		head = insertAtEnd(head);
	}
	seperateEven(&head);
	display(head);
}
