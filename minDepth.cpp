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
    int minDepth(TreeNode *root) {
        return minD(root, false);
    }
    int minD(TreeNode* root, bool hasB) {
        if(!root) return hasB?INT_MAX:0;
        return 1 + min(minD(root->left, root->right != NULL), minD(root->right, root->left!= NULL));
    }
};