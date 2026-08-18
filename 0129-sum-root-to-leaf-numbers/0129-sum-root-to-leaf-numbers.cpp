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
    void fun(TreeNode* root, int sum, int &ans){
        if(!root->left && !root->right){
            ans+=sum;
            return;
        }

        if(root->left){
            sum = ((10*sum)+root->left->val);
            fun(root->left,sum,ans);
            sum/=10;
        }

        if(root->right){
            sum = 10*sum+root->right->val;
            fun(root->right,sum,ans);
            sum/=10;
        }
        return;

    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int sum = root->val;
        fun(root,sum,ans);
        return ans;
    }
};