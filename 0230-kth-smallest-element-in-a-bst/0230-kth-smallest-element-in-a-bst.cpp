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

    void find_smallest(TreeNode* root, stack<TreeNode*> &st){
        if(root==NULL) return;

        st.push(root);
        find_smallest(root->left,st);
    }

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        find_smallest(root,st);
        TreeNode* temp  = NULL;
        for(k; k>0; k--){
            // val = st.top()->val;
            temp = st.top();
            st.pop();
            if(temp->right) find_smallest(temp->right,st);
        }
        return temp->val;
    }
};