#include<iostream>
using namespace std;
int main()
{
    double x,y,z;
    while(cin>>x>>y>>z)
    {
        if(x+y>z&&x+z>y&&y+z>x)
        {
            cout<<"Yes"<<endl;
        }
        else{
        cout<<"No"<<endl;
    }
    }
    return 0;
}
