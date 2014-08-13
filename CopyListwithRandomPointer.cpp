
 //Definition for singly-linked list with a random pointer.
 struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL || head->next == NULL)
        	return head;
        RandomListNode * temp = head;
        RandomListNode * head2 = head;
        
    }
};

