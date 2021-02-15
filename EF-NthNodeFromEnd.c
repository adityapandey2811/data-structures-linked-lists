//nth Node from last by Aditya
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
void main(){
    int i,k;
    //2 pointer approach
    node *head = NULL, *temp1 = NULL, *temp2 = NULL;
    for(i=5;i>0;i--){
        head = insertAtEnd(head);
    }
    printf("Enter k: ");
    scanf("%d",&k);
    if(k<=0){
        printf("Invalid Number!!!\n");
        return;
    }
    temp1 = temp2 = head;
    while(temp1){
        if(k>0){
            k--;
        }
        else{
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    if(k==0){
        printf("kth Node: %d\n",temp2->data);
    }
    else{
        printf("Invalid Number!!!\n");
    }
}

