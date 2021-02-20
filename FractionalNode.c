#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* fractionalNode(node *head, int k){
	int i = 0;
	node *temp = NULL;
	if(k==0 || head == NULL)
		return NULL;
	while(head){
		if(i%k==0){
			if(temp == NULL)
				temp = head;
			else
				temp = temp->next;
		}
		i++;
		head = head->next;
	}
	return temp;
}
void main(){
	int i;
	node *head = NULL,*temp;
	for(i=0;i<10;i++){
		head = insertAtEnd(head);
	}
	temp = fractionalNode(head,3);
	printf("%d\n",temp->data);
}
