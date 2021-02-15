//Aditya's code for DoublyLinkedList
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
    struct n *prev;
}node;
//Display
void display(node *head){
    node *temp = head,*new;
    if(temp != NULL){
        while(temp){
            printf("%d ",temp->data);
            new = temp;
            temp = temp->next;
        }
        printf("\n");
        while(new){
            printf("%d ",new->data);
            new = new->prev;
        }
    }
    else{
        printf("List Empty");
    }
    printf("\n");
}
//Length
int length(node *head){
    int n = 0;
    node *temp = head;
    while(temp){
        n++;
        temp = temp->next;
    }
    return n;
}
//Insertion
node *insertAtStart(node *head){
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->prev = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    if(head == NULL){
        head = new;
    }
    else{
        new->next = head;
        head->prev = new;
        head = new;
    }
    return head;
}
node *insertAtMiddle(node *head){
    int n;
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->prev = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    printf("Enter Position: ");
    scanf("%d",&n);
    if(head == NULL){
        head = new;
    }
    else if(n <= 1){
        new->next = head;
        head->prev = new;
        head = new;
    }
    else if(n >= (length(head) + 1)){
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    else{
        while(n-2>0){
            temp = temp->next;
            n--;
        }
        new->next = temp->next;
        temp->next = new;
        new->prev = temp;
        new->next->prev = new;
    }
    return head;
}
node *insertAtEnd(node *head){
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->prev = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    if(head == NULL){
        head = new;
    }
    else{
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    return head;
}
//Deletion
node *deleteAtStart(node *head){
    node *temp = head;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else{
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        free(temp);
    }
    return head;
}
node *deleteAtEnd(node *head){
    node *temp = head,*new;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else if(temp->next != NULL){
        while(temp->next->next){
            temp = temp->next;
        }
        new = temp->next;
        temp->next = NULL;
        free(new);
    }
    else{
        free(head);
        head = NULL;
    }
    return head;
}
node *deleteAtMiddle(node *head){
    int n;
    node *temp = head,*new;
    printf("Enter Position: ");
    scanf("%d",&n);
    if(n <= 1){
        head = deleteAtStart(head);
    }
    else if(n >= (length(head)+1)){
        head = deleteAtEnd(head);
    }
    else{
        while((n--)-2>0){
            temp = temp->next;
        }
        new = temp->next;
        temp->next = new->next;
        free(new);
        temp->next->prev = temp;
    }
    return head;
}
node *deleteList(node *head){
    node *temp = head;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else{
        while(temp){
            temp = head->next;
            free(head);
            head = temp;
        }
    }
    return head;
}
//Main Function
void main(){
    int i;
    node *head = NULL;
    printf("Enter:\n1. Insert at start\n2. Insert at given position\n3. Insert at end\n4. Display\n5. Length\n6. Delete at start\n7. Delete at given position\n8. Delete at end\n9. Delete list\n10. End\n");
    while(i!=10){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1)
            head = insertAtStart(head);
        else if(i==2)
            head = insertAtMiddle(head);
        else if(i==3)
            head = insertAtEnd(head);
        else if(i==4)
            display(head);
        else if(i==5)
            printf("Length: %d\n",length(head));
        else if(i==6)
            head = deleteAtStart(head);
        else if(i==7)
            head = deleteAtMiddle(head);
        else if(i==8)
            head = deleteAtEnd(head);
        else if(i==9)
            head = deleteList(head);
    }
}

