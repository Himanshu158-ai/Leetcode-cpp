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

    TreeNode* fun(unordered_map<int,int>& mapi, vector<int>& post, int &idx, int st, int lst){
        if(st>lst || idx<0) return NULL;

        TreeNode* node = new TreeNode(post[idx]);
        int new_lst = mapi[post[idx--]];
        node->right = fun(mapi,post,idx,new_lst+1,lst);
        node->left = fun(mapi,post,idx,st,new_lst-1);

        return node;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> mapi;
        for(int i = 0; i<in.size(); i++){
            mapi[in[i]] = i;
        }

        int idx = post.size()-1;
        int lst = idx;
        int st = 0;
        return fun(mapi,post,idx,st,lst);
    }
};