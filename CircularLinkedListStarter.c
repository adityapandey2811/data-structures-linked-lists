//Aditys's code for Circular Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
}node;
//Display
void display(node *head){
    node *temp = head;
    if(head == NULL){
        printf("List Empty!!!\n");
        return;
    }
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
}
//Length
int length(node *head){
    int n=0;
    node *temp = head;
    if(head == NULL){
        return 0;
    }
    do{
        temp = temp->next;
        n++;
    }while(temp != head);
    return n;
}
//Insertion
node *insertAtStartOrEnd(node *head, int n){
    node *temp = head,*new = NULL;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    if(head == NULL){
        head = new;
        new->next = head;
    }
    else{
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
        //Statement to check where to insert(Start or End)
        if(n == 1){
            head = new;
        }
    }
    return head;
}
node *insertAtMiddle(node *head){
    node *temp = head,*new = NULL;
    int n;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    printf("Enter Position: ");
    scanf("%d",&n);
    if(head == NULL){
        head = new;
        new->next = head;
    }
    else{
        if(n<=1){
            head = insertAtStartOrEnd(head,1);
        }
        else if(n >= (length(head) + 1)){
            head = insertAtStartOrEnd(head,0);
        }
        else{                                                                       
            while(n-2>0){
                temp = temp->next;
                n--;
            }
            printf("Enter Data: ");
            scanf("%d",&new->data);
            new->next = temp->next;
            temp->next = new;
        }
    }
    return head;
}
//Deletion
node *deleteAtStart(node *head){
    int n;
    node *temp = head,*new = head;
    if(head == NULL){
        printf("List Empty!!!\n");
        return NULL;
    }
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = head->next;
    //Statement to check for head node
    if(head == head->next){
        head = NULL;
    }
    else{
        head = head->next;
    }
    free(new);
    return head;
}
node *deleteAtEnd(node *head){
    int n;
    node *temp = head,*new = NULL,*prev = head;
    if(head == NULL){
        printf("List Empty!!!\n");
        return NULL;
    }
    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    //Statement to check for head node
    if(temp->next == temp){
        head = NULL;
    }
    free(temp);
    return head;
}
node *deleteAtMiddle(node *head){
    int n;
    node *temp = head,*new = NULL;
    if(head == NULL){
        printf("List Empty!!!\n");
        return NULL;
    }
    printf("Enter Position: ");
    scanf("%d",&n);
    if(n<=1){
        head = deleteAtStart(head);
    }
    else if(n>=(length(head) + 1)){
        head = deleteAtEnd(head);
    }
    else{
        while((n--)-2>0){
            temp = temp->next;
        }
        new = temp->next;
        temp->next = new->next;
        free(new);
    }
    return head;
}
node *deleteList(node *head){
    node *temp = head,*new = NULL;
    temp = temp->next;
    while(temp!=head){
        new = temp;
        temp = temp->next;
        free(new);
    }
    free(head);
    head = NULL;
    return head;
}
//Main Function
void main(){
    node *head = NULL;
    int i=-1;
    
    printf("Enter:\n1. Insert at start\n2. Insert at given position\n3. Insert at end\n4. Display\n5. Length\n6. Delete at start\n7. Delete at given position\n8. Delete at end\n9. Delete list\n10. End\n");
 
    while(i!=10){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1)
            head = insertAtStartOrEnd(head,1);
        else if(i==2)
            head = insertAtMiddle(head);
        else if(i==3)
            head = insertAtStartOrEnd(head,0);
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

