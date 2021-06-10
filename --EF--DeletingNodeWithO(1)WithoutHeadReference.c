#include<stdio.h>
#include<stdlib.h>
#include"ll.h"
int main(){
    node *temp = NULL, *spare = NULL, *del = NULL;
    int i;
    for(i=1;i<=7;i++){
        temp = insertAtEnd(temp);
    }
    spare = temp;
    display(temp);
    for(i=0;i<3;i++){
        spare = spare->next;
    }
    display(spare);
    del = spare->next;
    //POWER OF POINTERS
    *spare = *(spare->next);
    //POWER OF POINTERS
    // free(del);
    display(temp);
    display(del);//WE CAN FREE DEL AS IT IS JUST A BLOCK OF MEMORY NOT NEEDED FOR LINKED LIST BUT STILL ATTACHED TO IT
    display(spare);
    return 0;
}
