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
	//D *pd = (D*)pb;  //�Ƿ�Ϸ���
	D* pd = dynamic_cast<D*>(pb); //��̬ת����Ҫ��֤������ת���İ�ȫ��
	if (pd != NULL)
		pd->show();
}

void main()
{
	D d;
	Base b;
	Active(&b);
}
