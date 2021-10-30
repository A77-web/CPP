#include<iostream>
using namespace std;
void* operator new(size_t sz)
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete(void* ptr)
{
	free(ptr);
}

void* operator new[](size_t sz)
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete[](void* ptr)
{
	free(ptr);
}

class Test
{
public:
	Test(int data = 0) : m_data(data)
	{
		cout << "Test::Test()" << endl;
	}
	~Test()
	{
		cout << "Test::~Test()" << endl;
	}
public:
	void* operator new(size_t sz)
	{
		void* ptr = malloc(sz);
		return ptr;
	}
	void operator delete(void* ptr)
	{
		free(ptr);
	}

	void* operator new[](size_t sz)
	{
		void* ptr = malloc(sz);
		return ptr;
	}
		void operator delete[](void* ptr)
	{
		free(ptr);
	}
public:
	void* operator new(size_t sz, Test* pt)
	{
		return &pt[0];
	}
private:
	int m_data;
};

void main()
{
	Test* pt = new Test; //operator new
	delete pt;

	Test* pta = new Test[10];
	new(pta)Test(1);

	delete[]pta;

	int ar[10];
	new(ar)int(100);
}

