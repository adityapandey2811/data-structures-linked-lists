//Aditya's code to check if list is palindrome or not
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Reverse half list
void reverse(node **head){
    node *temp = *head, *link = NULL,*new = *head;
    while(temp){
        new = new->next;
        temp->next = link;
        link = temp;
        temp = new;
    }
    *head = link;
}
//Check palindrome
void palindrome(node **head){
    node *temp1 = *head,*temp2 = *head,*new,*prev;
    if(!temp1){
        printf("NULL!!!\n");
        return;
    }
    while(temp2 && temp2->next){
        new = temp1;
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }
    if(temp2 != NULL){
        new = temp1;
        temp1 = temp1->next;
    }
    temp2 = *head;
    reverse(&temp1);
    prev = temp1;
    while(temp1){
        if (temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            break;
    }
    if(temp1 == NULL){
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
    reverse(&prev);
    new->next = prev;
}
//Main function
void main(){
    int i;
    node *head = NULL;
//List creation
    for(i = 10; i>0; i--){
        head = insertAtEnd(head);
    }
    palindrome(&head);
    display(head);
}

