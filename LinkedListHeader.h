//Linked list head by Aditya
#ifndef ll_h
#define ll_h
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int data;
	char val;
	struct n *next;
}node;
//Display Linklist
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
void displayC(node *head){
	node *d = head;
	if(d == NULL){
		printf("List Empty\n");
	}
	while(d!=NULL){
		printf("%c ",d->val);
		d=d->next;
	}
	printf("\n");
}
//Calculate Linklist Length
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
//Insertion Start
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
	int n;
	node *temp = head,*new;
	new = (node*)malloc(sizeof(node));
	new->next = NULL;
	printf("Enter Data: ");
	scanf("%d",&new->data);
	printf("Enter Postition: ");
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
node* insertC(node *head,char c){
	node *temp = head,*new;
	new = (node*)malloc(sizeof(node));
	new->next = NULL;
	new->val = c;
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
node* insert(node *head,int i){
	node *temp = head,*new;
	new = (node*)malloc(sizeof(node));
	new->next = NULL;
	new->val = i;
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
//Insertion End
//Deletion Linklist
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
	int n;
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
			temp = head;
			head = head->next;
			free(temp);
		}
	}
	return head;
}
//Deletion End
#endif
