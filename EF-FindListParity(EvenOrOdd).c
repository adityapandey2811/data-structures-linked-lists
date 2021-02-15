//Aditya’s code to find list parity
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void main(){
    node *head = NULL,*temp;
    int i;
    for(i=1;i>0;i--){
        head = insertAtEnd(head);
    }
    temp = head;
    while(temp && temp->next)
        temp = temp->next->next;
    if(!temp)
        printf("Even\n");
    else
        printf("Odd\n");
}

