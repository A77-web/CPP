class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
        return nullptr;
        //建立根节点
        TreeNode* root=new TreeNode(preorder[0]);
        //根据根节点 来找中序遍历的根节点 进行左右划分
        auto inroot=find(inorder.begin(),inorder.end(),preorder[0]);
        //根据上面的划分来确定中序遍历的左右子树
        vector<int> inleft(inorder.begin(),inroot);//中序左
        vector<int> inright(inroot+1,inorder.end());//中序右
        //划分前序数组 根据中序的大小；
        int inleftsize=inleft.size();
        vector<int> preleft(preorder.begin()+1,preorder.begin()+1+inleftsize);//前序左
        vector<int> preright(preorder.begin()+1+inleftsize,preorder.end());//前序右
        root->left=buildTree(preleft,inleft);
        root->right=buildTree(preright,inright);
        return root;
    }
};
