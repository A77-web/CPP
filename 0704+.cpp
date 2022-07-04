#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &e:v)
    {
        cin>>e;
    }
    
    int max=v[0];//保留的最大值
    int sum=0;//从开始到当前
  
    for(int i=0;i<n;i++)
    {
        if(sum<=0)
            sum=v[i];
        else
            sum+=v[i];
        if(max<sum)
            max=sum;
    }
    cout<<max;
    return 0;
}
