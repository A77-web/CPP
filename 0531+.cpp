#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    string str;
    //文件名
    unordered_map<string,int> mp;
    //记录次数
    vector<string> v;
    //按顺序保存出现的错误
    string num;
    //行号
    size_t pos;
    while(cin>>str>>num)
    {
        pos=str.rfind('\\');
        if(pos!=string::npos)
        {
            str=str.substr(pos+1);
        }
        if(str.size()>16)
        {
            str=str.substr(str.size()-16);
        }
        str+=" "+num;
        if(mp.count(str)==0)
            v.push_back(str);
        mp[str]++;    
    }
    int start=0;
    if(v.size()>8)
        start=v.size()-8;
    for(;start<v.size();start++)
    {
        cout<<v[start]<<" "<<mp[v[start]]<<endl;
    }
}
