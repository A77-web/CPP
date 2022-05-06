class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i-1;j++)
            {
                dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
