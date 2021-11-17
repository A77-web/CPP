#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int StrToInt(string str)
    {
        if (str.size() == 0)
            return 0;
        int i = 0;
        int sign = 1; //正数
        if (str[0] == '+' || str[0] == '-')
        {
            if (str[0] == '-')
                sign = -1; //负数
            i++;
        }

        int num = 0;
        while (i < str.size())
        {
            if (str[i] < '0' || str[i]>'9')
                return 0;
            num = num * 10 + str[i] - '0';
            i++;
        }

        return sign * num;
    }
};
void main()
{
    Solution A;
}