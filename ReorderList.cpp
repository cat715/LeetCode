/**
 * Definition for singly-linked list.
 */
 #include <iostream>
 #include <cstdlib>
 using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void reorderList(ListNode *head) {
    	if (head == NULL || head->next == NULL)
    		return;
        ListNode *slowhead = head;
        ListNode *fasthead = head;
        while(fasthead->next != NULL){
        	fasthead = fasthead->next;
        	if (fasthead->next != NULL)
        		fasthead = fasthead->next;
        	else
        		break;
        	slowhead = slowhead->next;
        }
        //中间分链表，形成两个链表，逆序后半部分，与前半部分依次连接
        ListNode *head1 = head;
        ListNode *head2 = slowhead->next;
        slowhead->next = NULL;
        //逆序后半部分链表
        ListNode *cur = head2;
        ListNode *post = head2->next;
        cur->next = NULL;
        while(post != NULL) {
        	ListNode *temp = post->next;
        	post->next = cur;
        	cur = post;
        	post = temp;
        }
        head2 = cur;
        //合并两个链表
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        while(p2 != NULL){
        	ListNode *temp1 = p1->next;
        	ListNode *temp2 = p2->next;
        	p1->next = p2;
        	p2->next = temp1;
        	p1 = temp1;
        	p2 = temp2;
        }

    }
};

int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	a->next = b;
	b->next = c;
	c->next = d;
	Solution s;
	s.reorderList(a);
	ListNode *t = a;
	while(t != NULL){
		cout << t->val <<" ";
		t = t->next;
		//t++;
	}
	cout << endl;
	
	return 0;
}