#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void main()
{
	vector<int>iv = { 1,3,2,5,7,6 };
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;

	make_heap(iv.begin(), iv.end());

	iv.push_back(10);
	push_heap(iv.begin(), iv.end());
	for (const auto& e : iv)
		cout << e << " ";
	cout << endl;
}
