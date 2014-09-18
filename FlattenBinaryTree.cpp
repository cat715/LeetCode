/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode * temp = s.top();
            s.pop();
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
            temp->left = NULL;
            if(!s.empty())
                temp->right = s.top();
        }
    }
};