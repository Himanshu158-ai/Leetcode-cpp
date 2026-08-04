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
    void printer(queue<TreeNode*> &q, vector<vector<int>>& ans){
        if(q.empty())return;

        int size = q.size();
        vector<int>store;
        while(size!=0){
            store.push_back(q.front()->val);
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
            size--;
        }
        printer(q,ans);
        ans.push_back(store);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans ;
        
        queue<TreeNode*>q;
        q.push(root);
        printer(q,ans);
        return ans;
    }
};