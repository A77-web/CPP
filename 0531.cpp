class Solution {
public:
    bool _isSymmetric(TreeNode* q,TreeNode* p)
    {
        if(q==nullptr&&p==nullptr)
        return true;
        if(q==nullptr||p==nullptr)
        return false;
        return (q->val==p->val)&&(_isSymmetric(q->left,p->right)&&_isSymmetric(q->right,p->left));
    }
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root,root);
    }
};
