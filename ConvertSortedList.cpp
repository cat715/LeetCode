class Solution {  
public:  
    TreeNode *sortedListToBST(ListNode *head) {  
        if(head==NULL)return NULL;  
        ListNode *mid=head,*preMid=NULL,*tail=head->next;  
        while(tail){  
            tail=tail->next;  
            if(tail)tail=tail->next;  
            preMid=mid;  
            mid=mid->next;  
        }  
        TreeNode *cur = new TreeNode(mid->val);  
        if(preMid==NULL)cur->left=NULL;  
        else{  
            preMid->next=NULL;  
            cur->left = sortedListToBST(head);  
        }  
        cur->right = sortedListToBST(mid->next);  
        return cur;  
    }  
};  