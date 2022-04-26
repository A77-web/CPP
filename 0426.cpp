class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=0;
        int ans=nums[0];
        for(auto &e: nums)
        {
            res=max(res+e,e);
            ans=max(res,ans);
        }
        return ans;
    }
};
