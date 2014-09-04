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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL) return result;
        TreeNode *p = root;
        stack<TreeNode *> s;
        while(p || !s.empty()) {
            if(p) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
            
        }
        return result;
    }
};