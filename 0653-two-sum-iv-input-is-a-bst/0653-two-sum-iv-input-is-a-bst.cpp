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


// class Solution {
// public:
//     void fun(TreeNode* root, vector<int>& ans){
//         if(root==NULL) return;

//         fun(root->left,ans);
//         ans.push_back(root->val);
//         fun(root->right,ans);
//         return;
//     }

//     bool findTarget(TreeNode* root, int k) {
//         vector<int> ans;
//         fun(root,ans);
//         int i = 0, j = (int)ans.size()-1;
//         while(i<j){
//             if(ans[i]+ans[j]==k) return true;
//             else if(ans[i]+ans[j]>k) j--;
//             else i++;
//         }
//         return false;
//     }
// };


class Solution {
public:

    void smallest(TreeNode* root,stack<TreeNode*>& small){
        if(root==NULL) return;

        small.push(root);
        smallest(root->left,small);
        return;
    }
    void greatest(TreeNode* root,stack<TreeNode*>& great){
        if(root==NULL) return;

        great.push(root);
        greatest(root->right,great);
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        stack<TreeNode*>small;
        stack<TreeNode*>great;

        smallest(root,small);
        greatest(root,great);

        int greatVal = great.top()->val;
        int smallVal = small.top()->val;
        
        while(greatVal>smallVal){
            int sum = greatVal+smallVal;
            if(sum<k){
                TreeNode* temp = small.top();
                small.pop();
                smallest(temp->right,small);
                if(small.empty()) return false;
                smallVal = small.top()->val;
            }else if(sum>k){
                TreeNode* temp = great.top();
                great.pop();
                greatest(temp->left,great);
                if(great.empty()) return false;
                greatVal = great.top()->val;
            }else return true;
        }

        return false;
    }
};