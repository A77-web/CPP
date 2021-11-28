#include<iostream>
#include<string>
using namespace std;
int GetLenLastWord(string s)
{
    int pos = s.rfind(' ');
    //如果只有一个单词
    if (pos == string::npos)
        return s.size();
    return s.size() - pos - 1;
}
int main()
{
    string str;
    getline(cin, str);
    cout << GetLenLastWord(str);
    return 0;

}