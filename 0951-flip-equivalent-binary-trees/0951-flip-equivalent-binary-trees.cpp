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
    bool builder(TreeNode* root1, TreeNode* root2) {

        // Both are NULL
        if (root1 == NULL && root2 == NULL)
            return true;

        // One is NULL
        if (root1 == NULL || root2 == NULL)
            return false;

        // Values are different
        if (root1->val != root2->val)
            return false;

        // Case 1: Without Flip
        bool withoutFlip =
            builder(root1->left, root2->left) &&
            builder(root1->right, root2->right);

        // Case 2: With Flip
        bool withFlip =
            builder(root1->left, root2->right) &&
            builder(root1->right, root2->left);

        return withoutFlip || withFlip;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return builder(root1, root2);
    }
};