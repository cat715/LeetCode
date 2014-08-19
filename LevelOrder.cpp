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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        queue<TreeNode *>cur, next;
        vector<int> level;
        TreeNode *p = root;
        if (p!=NULL) cur.push(p);
        while (!cur.empty()) {
        	while (!cur.empty()) {
        		p = cur.front();
        		cur.pop();
        		level.push_back(p->val);
        		if (p->left != NULL) next.push(p->left);
        		if (p->right != NULL) next.push(p->right);
        	}
        	res.push_back(level);
        	level.clear();
        	swap(cur, next);
        }
        return res;
    }
};