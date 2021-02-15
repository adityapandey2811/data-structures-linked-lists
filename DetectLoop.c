//Detect Loop by Aditya
bool hasCycle(struct ListNode *head) {
        struct ListNode *fast = head, *slow = head;
        while(fast != NULL){
            if(fast->next != NULL)
                fast = fast->next;
            else
                break;
            if(fast->next != NULL)
                fast = fast->next;
            else
                break;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
}

