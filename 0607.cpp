#include<iostream>
using namespace std;
// version 1.0
//懒汉：单例实例时才被初始化，不适用则一直占用空间资源
class Singleton
{
private:
	static Singleton* instance;
private:
	Singleton(){}
	~Singleton(){}
	Singleton(const Singleton&){}
	Singleton& operator=(const Singleton&){}
private:
	class Deletor
	{
	public:
		~Deletor()
		{
			if (Singleton::instance != NULL)
			{
				delete Singleton::instance;
			}
		}
	};
public:
	static Singleton* getInstance()
	{
		if (instance == NULL)
			instance = new Singleton();
		return instance;
	}
};
Singleton* Singleton::instance = NULL;
//饿汉：指单例实例在程序运行时立即执行初始化
class eSingleton
{
private:
	static eSingleton instance;
private:
	eSingleton(){}
	~eSingleton(){}
	eSingleton(const eSingleton&){}
	eSingleton& operator =(const eSingleton&){}
public:
	static eSingleton& getInstance()
	{
		return instance;
	}
};
eSingleton eSingleton::instance;
