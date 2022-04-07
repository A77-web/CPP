class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return vector<vector<int> >();
        }
        queue<TreeNode*> q;
        q.push(root);
        
        int levelsize=1;
        vector<vector<int>> vv;
        while(!q.empty())
        {
            vector<int> v;
            for(int i=0;i<levelsize;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            vv.push_back(v);
            levelsize=q.size();
        }
        return vv;
        
    }
};
