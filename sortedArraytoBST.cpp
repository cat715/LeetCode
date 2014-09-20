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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;
        TreeNode *root = BST(num, 0, num.size()-1);
        return root;
    }
    TreeNode* BST(vector<int> &num, int start, int end) {
        if(start == end) {
            TreeNode * root = new TreeNode(num[start]);
            return root;
        }
        if(start > end)
            return NULL;
        int mid = (start + end)/ 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = BST(num, start, mid-1);
        root->right = BST(num, mid+1, end);
        return root;
    }
};