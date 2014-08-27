#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode * p = head;
        int c = 0, tmp = 0;
        while(p1 || p2 || tmp) {
        	if(p1 && p2) {
        		tmp = p1->val + p2->val + c;
        		c = tmp/10;
        		tmp = tmp%10;
        		p->next = new ListNode(tmp);
        		p1 = p1->next;
        		p2 = p2->next;
        		p = p->next;
        	} else if(p1 && !p2) {
        		tmp = p1->val + c;
        		c = tmp/10;
        		tmp = tmp%10;
        		p->next = new ListNode(tmp);
        		p1 = p1->next;
        		p = p->next;
        	} else if(p2 && !p1) {
        		tmp = p2->val + c;
        		c = tmp/10;
        		tmp = tmp%10;
        		p->next = new ListNode(tmp);
        		p2 = p2->next;
        		p = p->next;
        	} else if(!p1 && !p2) {
        		tmp = c;
        		c = 0;
        		p->next = new ListNode(tmp);
        	}
        }
        return head;
    }


    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
    	ListNode * head = new ListNode(-1);
    	ListNode * d = head;
    	int carry = 0;
    	ListNode *p1 = l1;
    	ListNode *p2 = l2;
    	while(p1 || p2) {
    		int a = p1==NULL ? 0 : p1->val;
    		int b = p2==NULL ? 0 : p2->val;
    		int c = (a + b + carry) % 10；
    		carry = (a + b + carry) / 10;
    		d->next = new ListNode(c);
    		d = d->next;
    		if(!p1) p1=p1->next;
    		if(!p2) p2 = p2->next;
    	}
    	if (c > 0)
    		d->next = new ListNode(c);
    	return head->next;
    }
};