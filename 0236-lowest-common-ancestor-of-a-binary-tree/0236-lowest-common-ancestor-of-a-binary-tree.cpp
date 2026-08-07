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

    int fun(TreeNode* root, TreeNode* p, TreeNode* q, queue<TreeNode*>& que){
        if(!root) return 0;

        int r1 = fun(root->left,p,q,que);
        int r2 = fun(root->right,p,q,que);
        int self = 0;
        
        if(root->val==p->val || root->val==q->val) self = 1;
        int total = r1+r2+self;
        if(total==2) {
            que.push(root);
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*>que;
        fun(root,p,q,que);
        return que.front();
    }
};