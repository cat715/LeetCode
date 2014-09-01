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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode tmphead(0);
        ListNode *p = head, *tail = &tmphead;//tail 为当前已经处理完的尾节点
        while(p)
        {
            ListNode *groupHead = p;
            int i = 1;
            for(i = 1; i < k && p->next != NULL; i++)p = p->next;
            if(i != k){tail->next = groupHead; return tmphead.next;}//最后不足k个节点
            p = p->next;
            pair<ListNode*, ListNode*>ht = reverseList(groupHead, p);
            tail->next = ht.first;
            tail = ht.second;
        }
        return tmphead.next;
    }
    //翻转链表,并返回翻转后链表的头结点和尾节点
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode *end)
    {
        ListNode *p = head, *newHead = NULL;
        while(p != end)
        {
            ListNode *tmp = p->next;
            p->next = newHead;
            newHead = p;
            p = tmp;
        }
        return make_pair(newHead, head);
    }
};