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

    int sum = 0;
    int helper(TreeNode* node, int max)
    {
        if(node == nullptr)
            return sum;

        if(max <= node->val)
        {
            sum++;
            max = node->val;
        }
        helper(node->left, max);
        helper(node->right, max);

        return sum;
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return helper(root, root->val);
    }
};
