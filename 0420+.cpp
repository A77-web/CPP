#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='_')
                continue;
            if(i>0&&str[i-1]=='_')
                cout<<(char)(str[i]-32);
            else
                cout<<str[i];
        }
        cout<<endl;
    }
}
