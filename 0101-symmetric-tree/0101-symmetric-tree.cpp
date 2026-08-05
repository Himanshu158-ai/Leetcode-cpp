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

    bool checker(TreeNode* lef, TreeNode* rig){
        if(lef==NULL && rig==NULL) return true;

        if(!lef || !rig || lef->val!=rig->val) return false;
        if(!checker(lef->left,rig->right)) return false;
        if(!checker(lef->right,rig->left)) return false;

        return true;

    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;

        return checker(root->left,root->right);
    }
};