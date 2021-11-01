#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class Test
{
public:
	//默认构造函数
	Test(int d = 0)
	{
		cout << "Create Test Object" << endl;
		m_data = d;
	}
	//拷贝构造方法
	Test(const Test& t)
	{
		cout << "Copy Create Test Object" << endl;
		m_data = t.m_data;
	}
	//赋值语句 等号的重载
	Test& operator=(const Test& t)
	{
		cout << "Assign." << this << ":" << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	//析构方法
	~Test()
{
		cout << "free Test Object" << endl;
}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};
Test fun(const Test& obj)
{
	int value = obj.GetData();
	return Test(value);
}
void main()
{
	Test t1(100);
	Test t2 = fun(t1);
}