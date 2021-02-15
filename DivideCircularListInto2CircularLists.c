//Aditya's code to divide circular list into 2 circular lists
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Display list
void displayCircular(node *head){
    node *temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}
//Dividing list 
node *divideLists(node **head){
    node *temp1 = *head, *temp2 = *head, *new;
    if(temp1->next == NULL){
        return NULL;
    }
    while(temp2->next!=*head && temp2->next->next!=*head){
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }
    if(temp2->next->next == *head)
        temp2 = temp2->next;
    new = temp1;
    temp1 = temp1->next;
    temp2->next = temp1;
    new->next = *head;
    return temp1;
}
//Main function
void main(){
    int i;
    node *head1 = NULL, *temp, *head2 = NULL;
//Creating list
    for(i=11;i>0;i--){
        head1 = insertAtEnd(head1);
    }
//Converting list to circular
    temp = head1;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head1;
    head2 = divideLists(&head1);
    displayCircular(head1);
    displayCircular(head2);
}

