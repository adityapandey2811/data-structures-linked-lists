//Aditya’s code to merge sorted lists
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Merging
node *mergeSortedList(node *head1, node* head2){
    node *temp1 = head1, *temp2 = head2, *new, *head;
//Capture head pointer
    (temp1->data>temp2->data)?(head = temp2):(head = temp1);
    while(temp1 && temp2){
        if(temp1->data >= temp2->data){
            head2 = head2->next;
            temp2->next = temp1;
            temp2 = head2;
        }
        else{
            head1 = head1->next;
            temp1->next = temp2;
            temp1 = head1;
        }
    }
    return head;
}
//Main function
void main(){
    node *head = NULL,*head1 = NULL,*head2 = NULL;
    int i;
//List Creation
    for(i=2;i>0;i--){
        head1 = insertAtEnd(head1);
    }
    for(i=7;i>0;i--){
        head2 = insertAtEnd(head2);
    }
//Storing merged list in head
    head = mergeSortedList(head1,head2);
    display(head);
}

