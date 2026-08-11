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
    int fun(TreeNode* node){
        if(!node->left && !node->right) return 1;

        int lft = INT_MAX;
        int rgh = INT_MAX;
        if(node->left) lft = fun(node->left);
        if(node->right) rgh = fun(node->right);
        
        return 1+(min(lft,rgh));
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return fun(root);
    }
};