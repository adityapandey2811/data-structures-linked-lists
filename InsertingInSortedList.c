//Aditya’s code for inserting in sorted list
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
node *insert(node *head){
    node *new = NULL,*temp = head,*prev = NULL;
    int i,j,k,n,flag = 0;
//Creating node
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    printf("Enter data: ");
    scanf("%d",&new->data);
//Traversing sorted list and inserting value
    while(temp->next){
        if(new->data>temp->data){
            prev = temp;
            temp = temp->next;
        }
        if(new->data<=temp->data){
            if(temp!=head){
                prev->next = new;
                new->next = temp;
                flag = 1;
                break;
            }
            else{
                new->next = head;
                head = new;
                flag = 1;
                break;
            }
        }
    }
    if(!flag){
        temp->next = new;
    }
    return head;
}
//Main function
void main(){
    node *head = NULL;
    int i,j,k,n;
//Creating linked list    
    for(i=5;i>0;i--){
        head = insertAtEnd(head);
    }
    head = insert(head);
    display(head);
}

