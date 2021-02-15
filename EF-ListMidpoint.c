//Aditya’s code for finding midpoint in list
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Main function
void main(){
    int i;
    node *head = NULL,*temp1 = NULL,*temp2 = NULL;
//Creating list
    for(i=5;i>0;i--){
        head = insertAtEnd(head);
    }
//Finding midpoint using fast pointer approach
    temp1 = temp2 = head;
    while(temp2!=NULL && temp2->next!=NULL){
        temp2 = temp2->next;
        if(temp2->next!=NULL){
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
    }
    printf("Midpoint: %d\n",temp1->data);
}

