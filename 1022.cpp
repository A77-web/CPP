#include<iostream>
using namespace std;
class Test
{
public:
	Test(int data)
	{
		cout << "create Test Object" << endl;
		m_data = 0;
	}
	~Test()
	{
		cout << "Free Test Object" << endl;
	}
public:
	void initTest(int data = 0)
	{
		cout << "int Test." << endl;
		m_data = data;
	}
	void DestroyTest()
	{
		cout << "Destroy Test." << endl;
	}
private:
	int m_data;
};
int main() {
	Test* pt = new Test(10);
	delete pt;
}