#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
	String(const char* str = "") :m_data(nullptr)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s) :m_data(nullptr)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s) {
			delete[]m_data;
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[]m_data;
		m_data = nullptr;
	}
private:
	char* m_data;
};
void main() {
	String s1 = "abc";
	String s2 = s1;
	String s3;
	s3 = s2;
}