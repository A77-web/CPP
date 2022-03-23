#include<iostream>
#include<vector>
using namespace std;
int AddDigits(int num)
{
    if(num/10==0)
        return num;
    int sum=0;
    while(num/10!=0)
    {
        while(num)
        {
            sum+=num%10;
            num/=10;
        }
        if(num == 0 && sum / 10 != 0){
                num = sum;
                sum = 0;
            }

    }
    return sum;
}
int main()
{
   int x=0;
    while(cin>>x)
    {
    int ret=AddDigits(x);
       cout<<ret<<endl;
    }
    return 0;
}
