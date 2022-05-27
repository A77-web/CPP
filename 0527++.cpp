class Solution {
public:
    bool _isSymmetic(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL&&t2==NULL)
        return true;
        if(t1==NULL||t2==NULL)
        return false;
        return (t1->val==t2->val)&&(_isSymmetic(t1->left,t2->right)&&_isSymmetic(t1->right,t2->left));  
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL)
        return true;
        if(root->left==NULL||root->right==NULL)
        return false;
        return _isSymmetic(root->left,root->right);
    }
};
