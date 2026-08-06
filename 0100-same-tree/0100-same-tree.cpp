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

    bool checker(TreeNode* p, TreeNode* q){
        if(p==q) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val!=q->val) return false;
        if(!checker(p->left,q->left)) return false;
        if(!checker(p->right,q->right)) return false;

        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checker(p,q);
    }
};