#include<iostream>
using namespace std;
class A
{
public:
	//´¿Ðéº¯Êý
	virtual void Eat() = 0;
	virtual void Foot() = 0;
	virtual void Sleep() = 0;
};
class Dog :public A
{
public:
	void Eat()
	{
		cout << "Dog::Eat" << endl;
	}
	void Foot()
	{
		cout << "Dog::Foot" << endl;
	}
	void Sleep()
	{
		cout << "Dog::Sleep" << endl;
	}
};
class Pig :public A
{
public:
	void Eat()
	{
		cout << "PIG::Eat" << endl;
	}
	void Foot()
	{
		cout << "PIG::Foot" << endl;
	}
	void Sleep()
	{
		cout << "PIG::Sleep" << endl;
	}
};
class Bird :public A
{
public:
	void Eat()
	{
		cout << "Bird::Eat" << endl;
	}
	void Foot()
	{
		cout << "Bird::Foot" << endl;
	}
	void Sleep()
	{
		cout << "Bird::Sleep" << endl;
	}
public:
	virtual void Fly()
	{
		cout << "Bird::Fly";
	}
};
class TN:public Bird
{};
void action(A* pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}
int main()
{
	Dog dog;
	Pig pig;
	action(&dog);
	Bird b;
	b.Fly();
	TN t;
	t.Fly();
	return 0;
}