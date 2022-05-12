class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> st;
        for(auto &e:nums)
        {
            if(st.find(e)!=st.end())
            return false;
            if(e==0)
            continue;
            
            st.insert(e);
        }
        return (*st.rbegin()-*st.begin())<5;
    }
};
