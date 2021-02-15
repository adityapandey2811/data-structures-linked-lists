//Aditya's code for xor linked list(memory efficient doubly linked list) 
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
typedef struct n{
    int data;
    struct n *next;
}node;
//Convert links to XOR
node *xor(node *prev, node *next){
    return (node*) ((uintptr_t) (prev) ^ (uintptr_t) (next));
}
//Display
void display(node *head){
    node *temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//Insertion
node *insert(node *head){
    int i=1;
    node *temp,*newnode;
    while(i){
        printf("Enter: ");
        newnode = (node*)malloc(sizeof(node));
        newnode->next = NULL;
        scanf("%d",&i);
        newnode->data = i;
        if(head == NULL){
            head = newnode;
        }
        else{
            temp->next = newnode;
        }
        temp = newnode;
    }
    printf("List Created!!!\n");
    display(head);
    return head;
}
//Xor Display
void displayAterConversion(node *head){
    node *temp = head,*new = NULL,*link = NULL;
    while(temp){
        new = temp;
        printf("%d ",temp->data);
        link = xor(link,temp->next);
        if(link==NULL){
            break;
        }
        temp = link;        
        link = new;
    }
    printf("\nBackward Traversal\n");
    link = NULL;
    while(temp){
        new = temp;
        printf("%d ",temp->data);
        link = xor(link,temp->next);
        if(link == NULL){
            break;
        }
        temp = link;
        link = new;
    }
    printf("\n");
}
//Convert to Xor
node *convertToDoubly(node *head){
    node *temp = head,*new = head,*link = NULL;
    while(temp){
        link = temp->next;
        if(temp == head){
            temp->next = xor(NULL,temp->next);
        }
        else{
            temp->next = xor(new,link);
            new = temp;
        }
        temp = link;
    }
    return head;
}
//Main Function
void main(){
    node *head = NULL;
    head = insert(head);
    head = convertToDoubly(head);
    printf("List converted to memory efficient doubly linked list\n");
    displayAterConversion(head);
}

