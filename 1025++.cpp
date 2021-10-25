#include<iostream>
using namespace std;

int main()
{
    //定义day,表示每月的天数
    //判断年是否为闰年，是闰年则2月是29天，比和平年多一天
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int year, month, day, ret;
    while (cin >> year >> month >> day)
    {
        //错误类型判断
        if (year < 1 || month < 1 || month>12 || day < 1 || day>31 || (month == 2 && day > 29))
        {
            cout << "-1" << endl;
            break;
        }
        //处理正确类型
        int flage = 0;
        ret = 0;
        //判断是否是闰年,闰年标志位为1，不是闰年标志位为0
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
            flage = 1;
        ret += flage;         //+闰年的2月份多的那一天
        for (int i = 0; i < month - 1; ++i)
        {
            ret += days[i];  //+整月数
        }
        ret += day;          //+不完整月的天数
        cout << ret << endl;
    }
    return 0;
}