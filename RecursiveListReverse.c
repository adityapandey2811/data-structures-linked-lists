//Aditya’s code for recursive list reverse
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *reverse(node *head,node *temp){
//Reversing
    node *final;
    if(head->next==NULL){
        final = head;
    }
    else if(head->next!=NULL){
        temp = head;
        head = head->next;
        reverse(head,temp);
    }
    head->next = temp;
    if(temp!=NULL){
        temp->next = NULL;
    }
    return final;
}
//Main function
void main(){
    node *head = NULL;
//Creating list
    for(int i=10;i>0;i--){
        head = insertAtEnd(head);
    }
    head = reverse(head,NULL);
    display(head);
}
