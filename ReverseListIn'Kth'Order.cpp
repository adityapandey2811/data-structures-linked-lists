//Latest approach uses more memory
ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode *temp = head, *spare;
        int i,n = 0;
        if(k == 0)
            return head;
        if(!head)
            return NULL;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
            n++;
        }
        for(i=0;i+k<=n;i += k){
            reverse(v.begin() + i, v.begin() + i + k);
        }
        
        for(i=1;i<n;i++){
            v[i - 1]->next = v[i];
            // cout<<v[i]->val<<" ";
        }
        v[i-1]->next = NULL;
        // cout<<endl;
        return v[0];
    }
