#include<iostream>
#include<vector>
using namespace std;
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
int partition(vector<int>& v, int left, int right)
{
	int low = left, high = right-1;
	int key = v[low];
	while (low < high)
	{
		while (low< high && v[high]>key)
			high--;
		Swap(v[low], v[high]);
		while (low < high && v[low] <= key)
			low++;
		Swap(v[low], v[high]);
	}
	return low;
}
void quickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;
	int pos = partition(v, left, right);
	quickSort(v, left, pos);
	quickSort(v, pos + 1, right);
}
int main()
{
	vector<int> v = { 3, 8, 6, 4, 5, 1, 2 };

	quickSort(v, 0, v.size());
	for (auto& e : v)
	{
		cout << e << " ";
	}

}