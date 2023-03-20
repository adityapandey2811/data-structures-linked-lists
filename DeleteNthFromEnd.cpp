ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = new ListNode(), *p = head, *q = temp;
    temp->next = head;
    n--;
    while(n--){
        p = p->next;
    }
    while(p->next){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    return temp->next;
}
