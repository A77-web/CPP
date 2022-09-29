class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &e:nums)
        {
            ++mp[e];
        }
        int res=0;
        for(auto &[e,occ]:mp)
        {
            if(occ==1)
            res=e;
        }
        return res;
    }
};
