#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
bool IsAlpha(char ch)
{
    return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        for(int i=0;i<str.size();i++)
        {
            if(!IsAlpha(str[i]))
                str[i]=' ';
        }
        stringstream ss;
        ss<<str;
        vector<string> v;
        while(ss>>str)
        {
            v.push_back(str);
        }
        for(int i=v.size()-1;i>0;i--)
        {
            cout<<v[i]<<" ";
        }
        cout<<v[0]<<endl;
        
    }
    return 0;
}
