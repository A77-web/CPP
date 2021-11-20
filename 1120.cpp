#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
void main()
{
	vector<int>iv;
	iv.reserve(100000);
	clock_t start = clock();
	for (int i = 0; i < 100000; ++i)
	{
		iv.push_back(i);
	}
	clock_t end = clock();
	cout << end - start << endl;
}