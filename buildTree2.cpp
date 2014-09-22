
 #include <iostream>
 #include <vector>
 using namespace std;
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	TreeNode *root;
        if(preorder.size() == 0) return NULL;
        root = build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preS, int preE, int inS, int inE) {
    	if(preS > preE) return NULL;
    	if(inS > inE) return NULL;
    	TreeNode * root = new TreeNode(preorder[preS]);
    	int index = 0;
    	for(int i = inS; i <= inE; i++)
    		if(inorder[i] == preorder[preS]) {
    			index = i; break;
    		}
    	int left = index - inS;
    	//cout << index << "\t" << left << endl;
    	root->left = build(preorder, inorder, preS+1, preS+left, inS, inS+left - 1);
    	root->right = build(preorder, inorder, preS+left+1, preE, index+1, inE);
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	vector<int> ino;
	ino.push_back(2);
	ino.push_back(1);
	Solution s;
	s.buildTree(pre, ino);
	system("pause");
	return 0;
}