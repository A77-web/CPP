#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long a[100000];
    int k=-1;
    a[0]=1;
    a[1]=2;
 for(int i=2;i<100000;i++)
    {
        long long ans=a[i-1]+a[i-2];
        
        if(k==-1&&ans>=1000000)
        {
            k=i+1;
        }
        a[i]=ans%1000000;
    }
    int n;
    while(cin>>n)
    {
        if(n>=k)
        {
            printf("%06d\n",a[n-1]);
        }
        else
        {
            printf("%d\n",a[n-1]);
        }
    }
    
}
