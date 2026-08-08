/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void fun(TreeNode* root, TreeNode* p, TreeNode* q, queue<TreeNode*> &que){
        if(root==NULL) return;

        if(root->val>p->val && root->val>q->val) fun(root->left,p,q,que);
        else if(root->val<p->val && root->val<q->val) fun(root->right,p,q,que);

        que.push(root);
        return;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*>que;
        fun(root,p,q,que);
        return que.front();
    }
};