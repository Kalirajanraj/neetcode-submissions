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

    int diameter;
    int helper(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);

        diameter = max(leftHeight + rightHeight, diameter);

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        helper(root);
        return diameter;
    }
};
