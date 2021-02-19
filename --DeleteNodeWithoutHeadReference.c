void deleteNode(struct ListNode* node) {
    struct ListNode *prev;
    prev = node;
    node = node->next;
    prev->val = node->val;
    prev->next = node->next;
    free(node);
}

/* //////////////////OR///////////////////// */

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
