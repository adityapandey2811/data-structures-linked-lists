#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *evenOddConundrum(node *head){
	node *temp = head,*spare = NULL, *link = NULL,*even = NULL,*odd = NULL;
	while(temp){
		if(temp->data%2==0){
			if(spare == NULL)
				spare = temp;
			else
				even->next = temp;
			even = temp;
		}
		else{
			if(link == NULL)
				link = temp;
			else
				odd->next = temp;
			odd = temp;
		}
		temp = temp->next;
	}
	if(even!=NULL)
		even->next = link;
	if(odd!=NULL)
		odd->next = NULL;
	if(spare!=NULL)
		return spare;
	else
		return link;
}
void main(){
    node *head = NULL;
    int i;
    for(i=0;i<2;i++){
    	head = insertAtEnd(head);
    }
	head = evenOddConundrum(head);
	display(head);
}