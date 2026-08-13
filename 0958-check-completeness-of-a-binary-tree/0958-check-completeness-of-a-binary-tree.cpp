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

    // bool fun(queue<TreeNode*> &que){
        
    //     if(que.empty()) return true;
        
    //     int size = que.size();

    //     while(size){
    //         TreeNode * node = que.front();
    //         que.pop();


    //         if(!node){
    //             while(!que.empty()){
    //                 if(que.front()!=NULL) return false;
    //                 que.pop();
    //             }
    //             return true;
    //         }

    //         if(node->left) que.push(node->left);
    //         else que.push(NULL);

    //         if(node->right) que.push(node->right);
    //         else que.push(NULL);

    //         size--;
    //     }
    //     if(!fun(que)) return false;

    //     return true;


    // }
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool is_null = false;

        // recursive approach
        // return fun(que);



        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(node && is_null) return false;

            if(!node) {
                is_null = true;
                continue;
            }


            if(node->left) que.push(node->left);
            else que.push(NULL);

            if(node->right) que.push(node->right);
            else que.push(NULL);
        }
        return true;

    }
};