#include<iostream>
#include<cstdlib>
using namespace std;


struct ListNode
{
	/* data */
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
		{
			return false;
		}
		ListNode *slow, *fast;
		slow = head;
		fast = head->next;
		while(true) {
			if (fast == NULL)
			{
				return false;
			}
			fast = fast->next;
			if (fast == NULL)
			{
				return false;
			}
			if (fast == slow)
			{
				return true;
			}
			fast = fast->next;
			if (fast == NULL)
			{
				return false;
			}
			if (fast == slow)
			{
				return true;
			}
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	cout << "hello!" << endl;
	return 0;
}