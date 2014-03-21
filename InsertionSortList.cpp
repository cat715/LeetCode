/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode {
 	int val;
 	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
        if(head == NULL) return head;  
        ListNode dummy(-1);  
        dummy.next = head;  
        ListNode* prev = head;  
        ListNode* cur = prev->next;  
        while(cur)  
        {  
            if(cur->val >= prev->val)//greater or equal  
            {  
                prev = cur;  
                cur = cur->next;  
            }  
            else//smaller  
            {  
                //find the insert position  
                ListNode* insertPrev = &dummy;  
                ListNode* insertCur = dummy.next;  
                while(insertCur->val < cur->val)  
                {  
                    insertPrev = insertCur;  
                    insertCur = insertCur->next;  
                }  
                //then insert  
                prev->next = cur->next;  
                cur->next = insertCur;  
                insertPrev->next = cur;  
                cur = prev->next;  
            }  
        }  
        return dummy.next;  
    }
};

int main() {
ListNode t1(3);  
    ListNode t2(4);  
    ListNode t3(1);  
    t1.next = &t2;  
    t2.next = &t3;  
    ListNode *h = &t1;  
    while (h)  
    {  
        cout<<h->val<<" ";  
        h = h->next;  
    }  
    cout<<endl;  
    Solution solu;  
    h = &t1;  
    h = solu.insertionSortList(h);  
    while (h)  
    {  
        cout<<h->val<<" ";  
        h = h->next;  
    }  
    cout<<endl;  
  
    system("pause");  
    return 0;  
}
