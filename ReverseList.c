//Aditya’s code for reversing list
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *reverse(node *head){
    node *temp = head,*prev = NULL,*link = NULL;
//Reversing list
    while(temp){
        link = temp->next;
        temp->next = prev;
        prev = temp;
        temp = link;
    }
    head = prev;
    return head;
}
//Main function
void main(){
    node *head = NULL;
//Creating list
    for(int i=10;i>0;i--){
        head = insertAtEnd(head);
    }
    head = reverse(head);
    display(head);
}

