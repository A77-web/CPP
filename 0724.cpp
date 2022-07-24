class Solution {
public:
    int maxSubArray(vector<int>& nums) {
             int max=nums[0];//保留的最大值
    int sum=0;//从开始到当前

    for(int i=0;i<nums.size();i++)
    {
        if(sum<=0)
            sum=nums[i];
        else
            sum+=nums[i];
        if(max<sum)
            max=sum;
    }
    return max;
    }
};
