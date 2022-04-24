class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        //建立一个集合作为滑动窗口
        unordered_set<char> st;
        int ans=0;
        int left=0;
        for(int i=0;i<s.size();i++)
        {
            //如果abca 则把a删除 left向右移动一位
            while(st.find(s[i])!=st.end())
            {
                st.erase(s[left]);
                left++;
            }
            //取出最大的滑动窗口值
            ans=max(ans,i-left+1);
            st.insert(s[i]);
        }
        return ans;
    }
};
