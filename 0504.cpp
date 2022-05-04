class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        return n;
        sort(nums.begin(),nums.end());
        int res=1;
        int tmp=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            continue;
            if(nums[i+1]-1==nums[i])
            {
            
                ++tmp;
               res=max(res,tmp); 
            }
            else
            {
                tmp=1;
            }
            
        }
        return res;
    }
};
