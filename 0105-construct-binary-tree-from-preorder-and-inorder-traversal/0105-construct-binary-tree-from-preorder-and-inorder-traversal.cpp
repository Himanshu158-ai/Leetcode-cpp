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

    TreeNode* creating_tree(vector<int>& pre, unordered_map<int,int> &mapi, int st, int lst,int &idx){
        if(st>lst) return NULL;


        TreeNode* newNode = new TreeNode(pre[idx]);
        int indx = mapi[pre[idx++]];

        newNode->left = creating_tree(pre,mapi,st,indx-1,idx);
        newNode->right = creating_tree(pre,mapi,indx+1,lst,idx);

        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>mapi;
        for(int i = 0; i<in.size(); i++){
            mapi[in[i]] = i;
        }
        int idx = 0;
        return creating_tree(pre,mapi,0,pre.size()-1,idx);
    }
};