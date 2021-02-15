//Aditya's code for detect and end loop in linked list
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void main(){
    int i,counter = 0,flag = 0;
    node *head = NULL, *temp1 = NULL, *temp2 = NULL , *breakLink = NULL;
//Creating linked list
    for(i = 10 ; i > 0 ; i--){
        head = insertAtEnd(head);
    }
//Creating loop in linked list
    temp1 = temp2 = head;
    while(temp1->next){
        temp1 = temp1->next;
    }
    for(i=10;i>5;i--){
        temp2 = temp2->next;
    }
    temp1->next = temp2;
//Detecting loop using floyd’s algorithm
    temp1 = temp2 = head;
    while(temp1 || temp1->next){
        if(temp1->next!=NULL)
            temp1 = temp1->next;
        if(temp1->next!=NULL)
            temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2){
            printf("Loop Found\n");
            flag = 1;
            break;
        }
    }
//Finding start of loop using floyd’s algorithm
    if(flag){
        temp1 = head;
        breakLink = temp2;
        while(temp1!=temp2){
            breakLink = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        printf("Loop starting at %d\n",temp1->data);
//Length of loop(optional)
        do{
            temp2 = temp2->next;
            counter++;
        }while(temp2!=temp1);
//Breaking loop
        if(breakLink == temp2)
            while(breakLink->next!=temp2)
                breakLink = breakLink->next;
        breakLink->next = NULL;
        printf("Loop breaked!!!\nLength of loop: %d\n",counter);
    }
    else{
        printf("Loop not found!!!\n");
    }
    display(head);
}
 

