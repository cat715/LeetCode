/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        connctNext(root, NULL);
    }
    void connectNext(TreeLinkNode * root, TreeLinkNode * sib) {
    	if (root == NULL) return;
    	root->next = sib;
    	connectNext(root->left, root->right);
    	if (sib) connect (root->right, sib->left);
    	else connect(root->right, NULL);
    }
};