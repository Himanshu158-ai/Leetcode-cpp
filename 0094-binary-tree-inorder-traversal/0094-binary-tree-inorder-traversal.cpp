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

    void printer(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        printer(root->left,ans);
        ans.push_back(root->val);
        printer(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        printer(root,ans);
        return ans;
    }
};