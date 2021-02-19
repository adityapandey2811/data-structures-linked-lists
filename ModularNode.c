#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* modularNode(node *head, int k){
	int i = 0;
	node *temp;
	while(head){
		i++;
		if(i%k == 0)
			temp = head;
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
	temp = modularNode(head,4);
	printf("%d\n",temp->data);
}
