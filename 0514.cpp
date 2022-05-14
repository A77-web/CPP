class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0]==1)
        return 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return nums.size();
    }
};
