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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isSym(root->left, root->right);

    }
    bool isSym(TreeNode *root1, TreeNode *root2) {
    	if (root1 == NULL && root2 == NULL) return true;
    	if (root1->val == root2->val && root1->left->val == root2->right->val && root1->right->val == root2->left->val)
    		return isSym(root1->left, root2->right) && isSym(root1->right, root2->left);
    	return false;
    }
};