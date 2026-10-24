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
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int> preOrder, int left, int right)
    {
        if(left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preOrder[preIndex++]);
        int mid = mp[root->val];
        root->left = build(preOrder, left, mid - 1);
        root->right = build(preOrder, mid+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1);
    }
};
