struct Node* copyRandomList(struct Node* head) {
	struct Node *temp = head,*new,*link = NULL,*spare,*current;
    while(temp){
        new = (struct Node*)malloc(sizeof(struct Node));
        new->val = temp->val;
        new->next = NULL;
        if(link == NULL){
            link = new;
        }
        else{
            spare->next = new;
        }
        spare = new;
        spare->random = temp;
        current = temp;
        temp = temp->next;
        current->next = spare;
    }
    new = link;
    while(new){
        if(new->random->random != NULL)
            new->random = new->random->random->next;
        else
            new->random = NULL;
        new = new->next;
    }
    temp = head;
    new = link;
    while(new){
        temp->next = new->next;
        temp = temp->next;
        new = new->next;
    }
    return link;
}
