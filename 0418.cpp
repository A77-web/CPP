#include<iostream>
#include<vector>
using namespace std;
double sover(vector<vector<int>> &vv,int n,int m)
{
    vector<vector<double>> dp(n+1,vector<double>(m+1));
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!(i==1&&j==1))
            {
                dp[i][j]=dp[i][j-1]*(i==n?1.0:0.5)+dp[i-1][j]*(j==m?1.0:0.5);
            }
            if(vv[i][j]==1)
            {
                dp[i][j]=0.0;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        vector<vector<int>> vv(n+1,vector<int>(m+1));
        int x=0,y=0;
        while(k--)
        {
            cin>>x>>y;
            vv[x][y]=1;
        }
        printf("%.2f\n",sover(vv,n,m));
    }
    
    return 0;
}
