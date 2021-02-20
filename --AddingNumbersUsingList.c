#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node* addingConundrum(node *head1, node *head2){
	node *temp,*prev1,*prev2;
	static int carry = 0, current = 0;
	current++;
	if(head1!=NULL || head2!=NULL){
		if(head1!=NULL){
			prev1 = head1;
			head1 = head1->next;
		}
		if(head2!=NULL){
			prev2 = head2;
			head2 = head2->next;
		}
		temp = (node*)malloc(sizeof(node));
		temp->next = addingConundrum(head1,head2);
	}
	else
		return NULL;
	current--;
	temp->data = 0;
	if(prev1!=NULL)
		temp->data += prev1->data;
	if(prev2!=NULL)
		temp->data += prev2->data;
	if(prev1 == NULL && prev2 == NULL)
		return NULL;
	temp->data += carry;
	carry = temp->data/10;
	temp->data = temp->data%10;
	if(current == 1 && carry != 0){
		prev1 = (node*)malloc(sizeof(node));
		prev1->data = carry;
		prev1->next = temp;
		return prev1;
	}
	return temp;
}
node* addZero(node *head, int difference){
    node *temp,*spare = NULL,*prev;
    while(difference--){
        temp = (node*)malloc(sizeof(node));
        temp->data = 0;
        if(spare == NULL)
            spare = temp;
        else
            prev->next = temp;
        prev = temp;
    }
    prev->next = head;
    return spare;
}
void removeZeros(node **spare, node *head){
    node *temp = *spare, *remove;
    while(temp!=head){
        remove = temp;
        temp = temp->next;
        free(remove);
    }
}
node* manageOrientation(node *head1, node *head2){
    int l1,l2,difference;
    node *temp,*spare = NULL,*prev;
    l1 = length(head1);
    l2 = length(head2);
    if(l1 == l2){
        return addingConundrum(head1,head2);
    }
    else if(l1 > l2){
        difference = l1-l2;
        spare = addZero(head2,difference);
        temp = addingConundrum(head1,spare);
        removeZeros(&spare, head2);
    }
    else{
        difference = l2-l1;
        spare = addZero(head1,difference);
        temp = addingConundrum(head2,spare);
        removeZeros(&spare,head1);
    }
    return temp;
}
void main(){
	int i;
	node *head1 = NULL, *head2 = NULL, *head = NULL;
	for(i=0;i<6;i++){
		head1 = insertAtEnd(head1);
	}
	for(i=0;i<4;i++){
		head2 = insertAtEnd(head2);
	}
	head = manageOrientation(head1,head2);
	display(head);
    display(head1);
    display(head2);
}