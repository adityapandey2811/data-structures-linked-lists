#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* fractionalNode(node *head){
	node *temp = NULL;
	int i=1,k=1;
	while(head){
		if(i == k*k){
			if(temp == NULL)
				temp = head;
			else
				temp = temp->next;
			k++;
		}
		i++;
		head = head->next;
	}
	return temp;
}
void main(){
	int i;
	node *head = NULL,*temp;
	for(i=0;i<16;i++){
		head = insertAtEnd(head);
	}
	temp = fractionalNode(head);
	printf("%d\n",temp->data);
}