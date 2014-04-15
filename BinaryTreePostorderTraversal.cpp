/**
 * Definition for binary tree
  */
 #include <iostream>
 #include <cstdlib>
 #include <vector>
 #include <stack>
 using namespace std;
 struct TreeNode {
 	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        TreeNode * p;
        if (root == NULL) return v;
        s.push(root);
        while (s.empty() == false) {
        	p = s.top();
        	if ((p->left == NULL && p->right == NULL) ||
        		(pre != NULL && (pre == p->left || pre == p->right))) {
        		v.push_back(p->val);
        		s.pop();
        		pre = p;
        	} else {
        		if (p->right) s.push(p->right);
        		if (p->left) s.push(p->left);
        	}
        }
        return v;
    }
};

int main() {
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->right = b;
	b->left = c;
	Solution s;
	vector<int> result = s.postorderTraversal(a);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "  ";
	system("pause");
	return 0;
}