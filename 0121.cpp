#include<iostream>
using namespace std;
class Person
{
protected:
	string _name = "������";//����
	int _num = 111;//���֤��
};
class Student :public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl; 
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999;//ѧ��
};
void main()
{
	Student stu;
	stu.Print();
}