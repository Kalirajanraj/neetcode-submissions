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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> l;
        while(!q.empty())
        {
            if(q.front() == nullptr)
            {
                q.pop();
                ans.push_back(l);
                l.clear();
                if(!q.empty())
                    q.push(nullptr);
            }
            else
            {
                auto curr = q.front();
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);

                l.push_back(curr->val);
                q.pop();
            }
        }

        return ans;
    }
};
