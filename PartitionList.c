#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* partitionList(node *head, int X){
	int i = 0;
	node *lessThanX = NULL, *current = NULL, *moreThanX = NULL, *temp = head, *l, *m;
	lessThanX = (node*)malloc(sizeof(node));
	moreThanX = (node*)malloc(sizeof(node));
	l = lessThanX;
	m = moreThanX;
	while(temp){
		if(temp->data >= X){
			if(temp->data == X && i==0){
				current = temp;
				i++;
			}
			else{
				moreThanX->next = temp;
				moreThanX = moreThanX->next;
			}
		}
		else{
			lessThanX->next = temp;
			lessThanX = lessThanX->next;
		}
		temp = temp->next;
	}
	if(current!=NULL){
		lessThanX->next = current;
		lessThanX = lessThanX->next;
	}
	lessThanX->next = m->next;
	free(m);
	moreThanX->next = NULL;
	lessThanX = l->next;
	free(l);
	return lessThanX;
}
void main(){
	int i;
	node *head = NULL, *temp = NULL;
	for(i=0;i<10;i++){
		head = insertAtEnd(head);
	}
	printf("Enter partition value: ");
	scanf("%d",&i);
	temp = partitionList(head,i);
	display(temp);
}