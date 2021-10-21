#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	Date(const Date& d)
	{
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}
	//Date& operator=(const Date &d);
	~Date()
	{}
public:
	bool IsLeap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		return false;
	}
	int GetDayByYearMonth(int year, int month)
	{
		int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			if (IsLeap(year))
				month = 0;
		}
		return days[month];
	}
public:
	Date operator+(int n) //����+n��
	{
		int year = m_year;
		int month = m_month;
		int day = m_day;
		int days = GetDayByYearMonth(year, month);

		while (day + n > days)
		{
			month++;
			if (month > 12)
			{
				year++;
				month = 1;
			}
			n -= days;
			days = GetDayByYearMonth(year, month);
		}
		day += n;
		return Date(year, month, day);
	}
	Date& operator+=(int n)
	{
		Date tmp = *this + n;
		*this = tmp;
		return *this;
	}
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp = *this;
		++* this;
		return tmp;
	}
public:
	Date operator-(int n); //����-n��
	Date& operator-=(int n);
	Date& operator--();
	Date& operator--(int);
	Date operator-(const Date& d);
public:
	int GetWeek(int year, int month, int day); //���ڼ�
public:
	bool operator>(const Date& d)
	{
		if ((m_year > d.m_year)
			|| (m_year == d.m_year && m_month > d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day))
			return true;
		return false;
	}
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	bool operator<(const Date& d)
	{
		if ((m_year < d.m_year)
			|| (m_year == d.m_year && m_month < d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day))
			return true;
		return false;
	}
	bool operator >= (const Date& d)
	{
		return !(*this < d);
	}
	bool operator==(const Date& d)
	{
		return (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day);
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d.m_year << "��" << d.m_month << "��" << d.m_day << "��";
	return out;
}

////////////////////////////////////////////////////////////

void  main()
{
	Date dt1(2021, 10, 19);
	cout << "dt1 = " << dt1 << endl;

	//Date dt = dt1 + 13;
	//cout<<"dt = "<<dt<<endl;

	//dt1 += 100;
	Date dt2 = dt1++;
	cout << "dt1 = " << dt1 << endl;
	cout << "dt2 = " << dt2 << endl;
}