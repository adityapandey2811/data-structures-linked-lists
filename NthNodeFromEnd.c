//nth node from end
#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
int main(){
    int i,n,k;
    node *head = NULL,*temp;
    for(i = 10;i > 0;i--){
        head = insertAtEnd(head);
    }
    printf("Enter k: ");
    scanf("%d",&k);
    n = length(head);
    if(n>=k && k>0){
        n-=k;
        temp =head;
        while(n--){
            temp=temp->next;
        }
        printf("kth Node: %d\n",temp->data);
    }
    else{
        printf("Invalid Number!!!\n");
    }
    return 0;
}

