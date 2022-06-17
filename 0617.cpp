#include<iostream>
#include<vector>
using namespace std;
void Swap(int &left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
int position(vector<int>& v, int left, int right)
{
	int low = left;
	int high = right-1;
	int key = v[low];
	while (low<high)
	{
		while (low < high && key < v[high])			
		high--;
		Swap(v[low], v[high]);

		while (low < high && key >= v[low])			
		low++;
		Swap(v[low], v[high]);
	}
	return low;
}
void QuickSort(vector<int> &v, int left, int right)
{
	if (left >= right)
		return;
	int pos = position(v, left, right);
	QuickSort(v, left, pos);
	QuickSort(v, pos + 1, right);

}
int main()
{
	vector<int> v = { 3,6,5,99,77,44,22,88 };
	QuickSort(v, 0, v.size());
	for (auto& e : v)
	{
		cout << e << " ";
	}
}