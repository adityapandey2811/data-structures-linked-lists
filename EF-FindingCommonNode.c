//Aditya’s code for finding common node
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Finding common after subtraction
void findCommon(node *temp1,node *temp2){
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    printf("Common node at %d\n",temp1->data);
}
//Main Function
void main(){
    int i,j;
    node *head1 = NULL,*head2 = NULL,*temp1 = NULL,*temp2 = NULL;
//Creating Lists
    printf("Enter list 1\n");
    for(i=15;i>0;i--){
        head1 = insertAtEnd(head1);
    }
    printf("Enter list 2\n");
    for(i=7;i>0;i--){
        head2 = insertAtEnd(head2);
    }
//Joining Lists
    temp2 = head2;
    while(temp2->next){
        temp2 = temp2->next;
    }
    i=9;
    temp1 = head1;
    while(i--){
        temp1 = temp1->next;
    }
//Display lists
    printf("Lists before connection\nList 1\n");
    display(head1);
    printf("List 2\n");
    display(head2);
    printf("\n");
    temp2->next = temp1->next;
    printf("List connected\nAfter Connection\nList 1\n");
    display(head1);
    printf("List 2\n");
    display(head2);
    printf("\n");
//Difference between lists
    i = length(head1);
    j = length(head2);
    if(i==j){
        findCommon(head1,head2);
    }
    else if(i>j){
        i-=j;
        temp1 = head1;
        while(i--){
            temp1 = temp1->next;
        }
        findCommon(temp1,head2);
    }
    else{
        j-=i;
        temp2 = head2;
        while(j--){
            temp2 = temp2->next;
        }
        findCommon(head1,temp2);
    }
}

