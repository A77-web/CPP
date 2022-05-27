class Solution {
public:
    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL)
        return true;
        bool left_res=(root->left==NULL||(root->left->val==root->val&&isUnivalTree(root->left)));
        bool right_res=(root->right==NULL||(root->right->val==root->val&&isUnivalTree(root->right)));
        return left_res&&right_res;
    }
};
