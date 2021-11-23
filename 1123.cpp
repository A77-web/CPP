#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str.find_first_of(str[i]) == str.find_last_of(str[i]))
            {
                cout << str[i] << endl;
                break;
            }
            if (i == str.size() - 1)
                cout << -1 << endl;
        }
    }
    return 0;
}