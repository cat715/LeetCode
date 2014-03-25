#include <iostream>
#include <cstdlib>
using namespace std;
/*Given a linked list, return the node where the cycle begins. 
If there is no cycle, return NULL.*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *detectCycle(ListNode*head) {
		//ListNode
		ListNode *slow = head;
		ListNode *fast = head;
		while (true) {
			if (fast == NULL || fast->next == NULL)
			{
				return NULL;
			}
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				break;
			}
		}
		slow = head;
		while(true) {
			if (slow == fast)
			{
				return slow;
			}
			slow = slow->next;
			fast = fast->next;
		}
	}
};

int main()
{
	Solution s;
	//ListNode *head;
	ListNode A = ListNode(1);
	ListNode B = ListNode(2);
	A.next = &B;
	ListNode C = ListNode(3);
	B.next = &C;
	ListNode D = ListNode(4);
	C.next = & D;
	D.next = &B;
	ListNode *result =  s.detectCycle(&A);
	cout << result->val;
	system("pause");
	return 0;
}