/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        if(root==nullptr)
        return v;
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            v.push_back(front->val);
            if(front->left!=NULL)
            q.push(front->left);
            if(front->right!=NULL)
            q.push(front->right);
        }
        return v;
    }
};
