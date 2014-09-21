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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        if(root == NULL) return result;
        dfs(root, sum, result, path);
        return result;
    }
    void dfs(TreeNode *root, int gap, vector<vector<int> > &result, vector<int> &path) {
    	if(root == NULL) return;
    	path.push_back(root->val);
    	if(root->left == NULL && root->right == NULL && gap == root->val) {
    		result.push_back(path);
    	}
    	dfs(root->left, gap-root->val, result, path);
    	dfs(root->right, gap-root->val, result, path);
    	path.pop_back();
    }
};