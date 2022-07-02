#include<iostream>
#include<mutex>
using namespace std;
// version 1.0
//懒汉：单例实例时才被初始化，不适用则一直占用空间资源
class Singleton
{
private:
	static Singleton* instance;
	static mutex i_mutex;
private:
	Singleton(){}
	~Singleton(){}
public:
	static Singleton* getInstance()
	{
		i_mutex.lock();
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		i_mutex.unlock();
		return instance;
	}
};
//静态变量需要在类外初始化
Singleton* Singleton::instance = NULL;
//类外初始化锁
mutex Singleton::i_mutex;





//饿汉：指单例实例在程序运行时立即执行初始化
class eSingleton
{
private:
	static eSingleton instance;
private:
	eSingleton() {}
	~eSingleton() {}
public:
	static eSingleton& getInstance()
	{
		return instance;
	}
	static void print()
	{
		cout << "hello esinleton!" << endl;
	}
};
eSingleton eSingleton::instance;//饿汉模式的关键 ：初始化及实例化
int main()
{
	//eSingleton::getInstance().print();
	Singleton* p = Singleton::getInstance();
	cout << p << endl;
	return 0;
}
