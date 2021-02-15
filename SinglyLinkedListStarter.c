//Aditys’s Code for SinglyLinkList
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
}node;
//Display Linked list
void display(node *head){
    node *d = head;
    if(d == NULL){
        printf("List Empty\n");
    }
    while(d!=NULL){
        printf("%d ",d->data);
        d=d->next;
    }
    printf("\n");
}
//Length Linked List
int length(node *head){
    int i=1;
    node *temp = head;
    if(temp == NULL){
        printf("List Empty\n");
    }
    while(temp!=NULL){
        temp = temp->next;
        i++;
    }
    return i;
}
//Insertion Linked List
node* insertAtStart(node *head){
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    if(temp == NULL){
        head = new;
    }
    else{
        new->next = head;
        head = new;
    }
    return head;
}
node* insertAtGivenPostition(node *head){
    int i,j,k,n,x,v,c;
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    printf("Enter Data: ");
    scanf("%d",&new->data);
    printf("Enter Position: ");
    scanf("%d",&n);
    if(head == NULL){
        head = new;
    }
    else if(n<=1){
        new->next = head;
        head = new;
    }
    else if(n >= length(head)){
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new;
    }
    else{
        while((n--)-2>0){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}
node* insertAtEnd(node *head){
    node *temp = head,*new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
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
    }
    return head;
}
//Deletion Linked List
node* deleteAtStart(node *head){
    node *temp = head;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else{
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    return head;
}
node* deleteAtEnd(node *head){
    node *temp = head,*new = head;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else if(temp->next!=NULL){
        while(temp->next){
        new = temp;
        temp = temp->next;
        }
        temp->next = NULL;
        free(temp);
        new->next = NULL;
    }
    else{
        head = NULL;
        free(temp);
    }
    return head;
}
node* deleteAtGivenPosition(node *head){
    int i,j,k,n,x,v,c;
    node *temp = head,*new;
    printf("Enter position: ");
    scanf("%d",&n);
    if(head == NULL){
        printf("List Empty\n");
    }
    else if(n<=1){
        head = deleteAtStart(head);
    }
    else if(n >= length(head)-1){
        head = deleteAtEnd(head);
    }
    else{
        while(n-2>0){
            temp = temp->next;
            n--;
        }
        new = temp->next;
        temp->next = new->next;
        new->next = NULL;
        free(new);
    }
    return head;
}
node* deleteList(node *head){
    node *temp;
    if(temp == NULL){
        printf("List Empty\n");
    }
    else{
        while(head!=NULL){
            temp = head->next;
            head->next = NULL;
            free(head);
            head = temp;
        }
    }
    return head;
}
//Main Function
void main(){
    node *head = NULL;
    int i=0,j,k,n,x,v,c;
    
    printf("Enter:\n1. Insert at start\n2. Insert at a given position\n3. Insert at end\n4. Display\n5. Length\n6. Delete at start\n7. Delete at a given position\n8. Delete at end\n9. Delete list\n10. End\n");
 
    while(i!=10){
        printf("Enter: ");
        scanf("%d",&i);
        if(i==1)
            head = insertAtStart(head);
        else if(i==2)
            head = insertAtGivenPostition(head);
        else if(i==3)
            head = insertAtEnd(head);
        else if(i==4)
            display(head);
        else if(i==5)
            printf("Length: %d\n",(length(head)-1));
        else if(i==6)
            head = deleteAtStart(head);
        else if(i==7)
            head = deleteAtGivenPosition(head);
        else if(i==8)
            head = deleteAtEnd(head);
        else if(i==9)
            head = deleteList(head);
    }
}

