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

    int fun(TreeNode* node, int &mx){
        if(!node->left && !node->right) return 1;

        int left = 0;
        int right = 0;

        if(node->left) left = fun(node->left,mx);
        if(node->right) right = fun(node->right,mx);
        mx = max(mx,left+right);
        return 1+(max(left,right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        fun(root,mx);
        return mx;
    }
};