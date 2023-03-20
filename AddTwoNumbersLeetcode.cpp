ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *temp = new ListNode(), *ans = temp;
    int carry = 0, res = 0;
    while(l1 || l2){
        if(!l1){
            l1 = new ListNode(0);
        }
        else if(!l2){
            l2 = new ListNode(0);
        }
        res = l1->val + l2->val + carry;
        if(res/10 != 0){
            carry = 1;
            res %= 10;
        }
        else{
            carry = 0;
        }
        temp->next = new ListNode(res);
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(carry == 1){
        temp->next = new ListNode(1);
    }
    return ans->next;
}
