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

    void printer(stack<TreeNode*>& LtoR, stack<TreeNode*>& RtoL, vector<vector<int>>& ans){
        if(LtoR.empty() && RtoL.empty()) return;

        vector<int>store;
        if(LtoR.empty()){
            while(!RtoL.empty()){
                TreeNode* node = RtoL.top();
                store.push_back(node->val);
                if(node->right) LtoR.push(node->right);
                if(node->left) LtoR.push(node->left);
                RtoL.pop();
            }
        }else{
            while(!LtoR.empty()){
                TreeNode* node = LtoR.top();
                store.push_back(node->val);
                if(node->left) RtoL.push(node->left);
                if(node->right) RtoL.push(node->right);
                LtoR.pop();
            }
        }

        ans.push_back(store);
        printer(LtoR,RtoL,ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>LtoR;
        stack<TreeNode*>RtoL;

        vector<vector<int>> ans;
        if(!root) return ans;

        LtoR.push(root);

        printer(LtoR,RtoL,ans);

        return ans;
    }
};