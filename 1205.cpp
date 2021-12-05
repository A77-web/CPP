class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=size(nums);
        sort(nums.begin(),nums.end());
        return nums[n-k];

    }
};
