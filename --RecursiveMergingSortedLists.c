//Aditya’s code for merging sorted lists(recursively)
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Merging recursively
node *mergeSortedList(node *head1, node* head2){
    node *result = NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data >=head2->data){
        result = head2;
        result->next = mergeSortedList(head2->next,head1);
    }
    else{
        result = head1;
        result->next = mergeSortedList(head1->next,head2);
    }
    return result;
}
//Main function
void main(){
    node *head = NULL,*head1 = NULL,*head2 = NULL;
    int i;
//List creation
    for(i=2;i>0;i--){
        head1 = insertAtEnd(head1);
    }
    for(i=7;i>0;i--){
        head2 = insertAtEnd(head2);
    }
//Storing in head
    head = mergeSortedList(head1,head2);
    display(head);
}

