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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 != NULL) return l2;
        if (l1 != NULL && l2 == NULL) return l1;
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode *head;
        head->next = NULL;
        ListNode *next = head;
        cout << "!!";
        while (l1 != NULL || l2 != NULL) {
        	if (l1 == NULL) next->next = l2;
        	if (l2 == NULL) next->next = l1;
        	if (l1->val <= l2->val) {
        		next->val = l1->val;
        		l1 = l1->next;
        		next = next->next;
        	}
        	else {
        		next->val = l2->val;
        		l2 = l2->next;
        		next = next->next;
        	}
        }
        return head;
    }
};

int main() {
	Solution s;
	cout << "!!";
	
	ListNode *a1; 
	a1->val = 1; 
	ListNode *a2; 
	a2->val = 50; 
	ListNode *a3; 
	a3->val = 52; 
	/*a1->next = a2;
	a2->next = a3;
	a3->next = NULL;

	ListNode *b1; b1->val = 5;
	ListNode *b2; b2->val = 51;
	b1->next = b2;
	ListNode * h = s.mergeTwoLists(a1, b1);
	while(h->next != NULL) {
		cout << h->val << " ";
		h = h->next;
	}*/
	system("pause");
	return 0;
}