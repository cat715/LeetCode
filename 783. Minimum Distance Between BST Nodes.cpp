/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int min = INT_MAX, pre;
    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return 0;

        getMinDiff(root);
        return min;
    }

    void getMinDiff(TreeNode * root) {
        if (root == NULL) return;
        
        //go to the left
        getMinDiff(root->left);

        if(pre != NULL) 
            min = min <= root->val - pre ? min : root->val - pre;
        pre = root->val;

        getMinDiff(root->right);

    }

};
