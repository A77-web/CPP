class Solution {
public:
    void preorder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
        return ;
        res.push_back(root->val);
        preorder(root->left,res);
         preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<int> res;
        preorder(root,res);
        return res;
    }
};
