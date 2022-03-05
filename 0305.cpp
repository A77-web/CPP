#include<iostream>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        int s=0;
        int count=0;
        while(n)
        {
            if(n&1==1)
            {
                ++s;             //当前连续位
                count=s>count?s:count;   //最大连续位
            }
            else
                s=0;
            n=n>>1;   //右移一位
        }
        cout<<count<<endl;
    }
    return 0;
}
