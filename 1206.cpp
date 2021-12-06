class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int>st;
        int i=0,j=0;
        while(i<pushV.size())
        {
            if(pushV[i]!=popV[j])
            {
                st.push(pushV[i++]);
            }
            else{
                ++i,++j;
                while(!st.empty()&&st.top()==popV[j])
                {
                    st.pop();
                    ++j;
                }
            }
        }
        return st.empty();
    }
};
