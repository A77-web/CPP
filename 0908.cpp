class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &e:nums)
        {
            ++mp[e];
        }
        int ans=0;
        for(auto [e,occ]:mp)
        {
            if(occ!=1)
            ans=e;
        }
        return ans;
    }
};
