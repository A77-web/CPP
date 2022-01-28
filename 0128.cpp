#include<iostream>
using namespace std;
class Base
{
public:
	virtual void f()
	{
		cout << "Base::f" << endl;
	}
	virtual void g()
	{
		cout << "Base::g" << endl;
	}
	virtual void h()
	{
		cout << "Base::h" << endl;
	}
};

class Base1
{
public:
	virtual void f()
	{
		cout << "Base1::f" << endl;
	}
	virtual void g()
	{
		cout << "Base1::g" << endl;
	}
	virtual void h()
	{
		cout << "Base1::h" << endl;
	}
};

class Base2
{
public:
	virtual void f()
	{
		cout << "Base2::f" << endl;
	}
	virtual void g()
	{
		cout << "Base2::g" << endl;
	}
	virtual void h()
	{
		cout << "Base2::h" << endl;
	}
};

class D : public Base, public Base1, public Base2
{
public:
	virtual void f()
	{
		cout << "D::f" << endl;
	}
	virtual void g1()
	{
		cout << "D::g" << endl;
	}
	virtual void h1()
	{
		cout << "D::h" << endl;
	}
};

void main()
{
	D d;
	Base* pb = &d;
	pb->f();
	//pb>h1();

	Base1* pb1 = &d;
	pb1->f();

	Base2* pb2 = &d;
	pb2->f();
}