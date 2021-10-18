
#include<Windows.h>
#include<iostream>
using namespace std;

int Add(int a, int b)
{

	return a + b;

}

double Add(double a, double b)
{

	return a + b;
}

float Add(float a, float b)
{

	return a + b;

}
int main()
{

	cout << Add(1, 2) << endl;

	cout << Add(3.5, 4.5) << endl;

	cout << Add(2.22, 3.33) << endl;


	system("pause");
	return 0;
}