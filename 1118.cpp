#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String&operator=(const String&s)
	{
		if (this != &s)
		{
			
			char* new_data = new char[strlen(s.m_data) + 1];
			strcpy(new_data, s.m_data);
			delete[]m_data;
			m_data = new_data;
		}
	return *this;
	}
	~String()
	{
		if (m_data)
		{
			delete[]m_data;
			m_data = nullptr;
		}
	}
private:
	char *m_data;
};
void main()
{
	String s;
}
