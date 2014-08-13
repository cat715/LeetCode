class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return;
        ListNode * h = head->next;
        while(h != NULL && h->val == head->val)
        	h = h->next;
        ListNode *head2;
        head2 = h == head->next?

    }
};