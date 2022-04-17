#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        for(int i=0;i<str.size();i++)
        {
            if((str[i]>='0')&&(str[i]<='9'))
            {
                cout<<str[i];
            }
        }
        cout<<endl;
    }
    
}
