#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Stuent()" << endl;
	}
};
void main()
{
	//Student stu;��̬����
	//1 operator new����ռ�
	//2 �������
	Person* p = new Student;//��̬����
	//1 ��������
	//2 �ͷſռ�
	delete p;
}