#include<iostream>
using namespace std;

int main()
{
    //����day,��ʾÿ�µ�����
    //�ж����Ƿ�Ϊ���꣬��������2����29�죬�Ⱥ�ƽ���һ��
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int year, month, day, ret;
    while (cin >> year >> month >> day)
    {
        //���������ж�
        if (year < 1 || month < 1 || month>12 || day < 1 || day>31 || (month == 2 && day > 29))
        {
            cout << "-1" << endl;
            break;
        }
        //������ȷ����
        int flage = 0;
        ret = 0;
        //�ж��Ƿ�������,�����־λΪ1�����������־λΪ0
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
            flage = 1;
        ret += flage;         //+�����2�·ݶ����һ��
        for (int i = 0; i < month - 1; ++i)
        {
            ret += days[i];  //+������
        }
        ret += day;          //+�������µ�����
        cout << ret << endl;
    }
    return 0;
}