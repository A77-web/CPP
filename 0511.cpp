class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[right]+nums[left]>target)
            {
                right--;
            }
            else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else
            return {nums[left],nums[right]};
        }
        return {};
    }
};
