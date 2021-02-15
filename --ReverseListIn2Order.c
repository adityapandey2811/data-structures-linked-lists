//Aditya’s code for reversing list in 2 order
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Reverse function
void reverseInOrder(node **head){
    node *temp = *head,*new,*link;
    if(!temp || !temp->next) return;
    *head = temp->next;
    new = temp->next;
    temp->next = temp->next->next;
    new->next = temp;
    new = temp;
    temp = temp->next;
    while(temp && temp->next){
        link = temp->next;
        temp->next = temp->next->next;
        link->next = temp;
        new->next = link;
        temp = temp->next;
        new = link->next;
    }
}
//Main function
void main(){
    node *head = NULL;
    int i;
//Creating list
    for(i = 3; i>0 ; i--){
        head = insertAtEnd(head);
    }
    reverseInOrder(&head);
    display(head);
}


