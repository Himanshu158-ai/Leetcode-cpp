/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root){
        if(!root->left && !root->right) return 1;
        int left = INT_MIN;
        int right = INT_MIN;
        if(root->left) left = fun(root->left);
        if(root->right) right = fun(root->right);
        return 1+(max(left,right));
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return fun(root);
    }
};