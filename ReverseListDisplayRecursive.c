//Aditya’s code for backward list display
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
//Displaying using recursion
void recursiveDisplay(node *head){
    if(head->next!=NULL){
        recursiveDisplay(head->next);
        
    }
    printf("%d ",head->data);
}
//Main Function
void main(){
    int i;
    node *head = NULL;
    for(i=10;i>0;i--){
        head = insertAtEnd(head);
    }
    recursiveDisplay(head);
}

