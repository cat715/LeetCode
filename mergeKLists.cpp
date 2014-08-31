/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return NULL;
        ListNode* p= lists[0];
        for(int i = 1; i < lists.size(); i++)
            p = mergeTwo(p, lists[i]);
        return p;
        
    }
    ListNode *mergeTwo(ListNode* p1, ListNode *p2) {
        ListNode * head = new ListNode(-1);
        ListNode * p = head;
        while(p1 != NULL || p2 != NULL) {
            int val1 = p1 == nullptr ? INT_MAX : p1->val;
            int val2 = p2 == nullptr ? INT_MAX : p2->val;
            if (val1 <= val2) {
                p->next = p1;
                p1 = p1->next;
            }else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        return head->next;
    }
};