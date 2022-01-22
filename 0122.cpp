#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{}
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
private:
	int m_a;
};

class D : public Base
{
public:
	void fun()
	{
		cout << "D::fun()" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
		m_d = 0;
	}
private:
	int m_d;
};

void Active(Base* pb)
{
	//D *pd = (D*)pb;  //是否合法？
	D* pd = dynamic_cast<D*>(pb); //动态转换主要保证了向下转换的安全性
	if (pd != NULL)
		pd->show();
}

void main()
{
	D d;
	Base b;
	Active(&b);
}
