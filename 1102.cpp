#include<iostream>
using namespace std;
namespace MySpace
{
	void fun() {
		cout << "This is my fun" << endl;
	}
}
namespace YouSpace
{
	void fun()
	{
		cout << "this is your fun" << endl;
	}
}
using namespace YouSpace;
void main()
{
	fun();
}
