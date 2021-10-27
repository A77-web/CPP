#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class string;
//引用计数器类
class String_rep
{
	friend class String;
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String_rep(const char* str = "") : use_count(0)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String_rep(const String_rep& rep) :use_count(0)
	{
		m_data = new char[strlen(rep.m_data) + 1];
		strcpy(m_data, rep.m_data);
	}
	String_rep& operator=(const String_rep& rep);
	~String_rep()
	{
		delete[]m_data;
		m_data = nullptr;
	}
public:
	void increment()
	{
		++use_count;
	}
	void decrement()
	{
		--use_count;
		if (--use_count == 0)
		{
			delete this;//自杀
		}
	}

private:
	char* m_data;
	size_t use_count;
};
class String
{
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = "") :m_rep(new String_rep(str))
	{
		m_rep->increment();
	}
	String(const String& s) :m_rep(s.m_rep)
	{
		m_rep->increment();
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			m_rep->decrement();
			m_rep = s.m_rep;
			m_rep->increment();
		}
		return *this;
	}
	~String()
	{
		m_rep->decrement();
	}
public:
private:
	String_rep* m_rep;
};
ostream& operator<<(ostream& out, const String& s)
{
	out << s.m_rep->m_data;
	return out;
}
void main()
{
	String s("abc");
	String s1 = s;
	String s2;
	s2 = s1;
	cout << "s = " << s << endl;
	//cout<<"s1 = "<<s1<<endl;
}