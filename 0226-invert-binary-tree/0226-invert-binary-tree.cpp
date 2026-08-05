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

    void create(TreeNode* root, queue<TreeNode*>& q){
        if(q.empty()) return;

        int size = q.size();
        while(size){
            TreeNode* node = q.front();
            TreeNode* R = node->right;
            TreeNode* L = node->left;

            node->left = R;
            node->right = L;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            q.pop();
            size--;
        }
        create(root,q);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        create(root,q);
        return root;
    }
};