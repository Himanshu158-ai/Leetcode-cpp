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
    void fun(TreeNode* root, int target, vector<int> &store, vector<vector<int>> &ans){
        if(target==0 && !root->left && !root->right){
            ans.push_back(store);
            return;
        }
        if(!root->left && !root->right) return;


        if(root->left) {
            store.push_back(root->left->val);
            fun(root->left, target-root->left->val, store, ans);
            store.pop_back();
        };

        if(root->right) {
            store.push_back(root->right->val);
            fun(root->right, target-root->right->val, store, ans);
            store.pop_back();
        }

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        if(!root) return ans;
        store.push_back(root->val);
        fun(root,target-root->val,store,ans);
        return ans;
    }
};