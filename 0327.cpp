#include<iostream>
using namespace std;
int main()
{
  int n=0;
  while(cin>>n)
  {
    cout<<n<<"=";
    for(int i=0;i<n;i++)
    {
      while(n%i==0&&i!=n)
      {
        n/=i;
        cout<<n<<"*";
      }
    }
    cout<<n<<end;
  }
}
