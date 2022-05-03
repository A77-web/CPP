#include<iostream>
#include<vector>
using namespace std;
void Swap(int &left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//快速排序
int partion(vector<int>& v, int left, int right)
{
	int low = left;
	int high = right - 1;
	int key = v[low];
	while (low < high)
	{
		while (low<high && v[high]>key)
			high--;
		Swap(v[low], v[high]);

		while (low < high && v[low] <=key)
			low++;
		Swap(v[low],v[high]);
	}
	return low;
}
void quickSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;
	int pos = partion(v, left, right);
	quickSort(v, left, pos);
	quickSort(v, pos + 1, right);
}
void Insert(vector<int>& v, int left, int right)
{
	for (int i = left+1; i < v.size(); i++)
	{
		int k = left;
		while (v[i] > v[k])
			k++;
		int tmp = v[i];
		for (int j = i; j > k; --j)
		{
			v[j] = v[j - 1];
		}
		v[k] = tmp;
	}
}
//直接插入排序
void Insert1(vector<int>& v, int left, int right)
{
	for (int i = left + 1; i < v.size(); i++)
	{
		int j = i;
		while (j > left && v[j] < v[j - 1])
		{
			Swap(v[j], v[j - 1]);
			j--;
		}
		
	}
}
//希尔排序
void ShellSort(vector<int>&v,int left, int right)
{
	int gap = right - left;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = left + gap; i < right; i++)
		{
			if (v[i] < v[i - gap])
			{
				int end = i;
				Swap(v[end], v[end - gap]);
				end -= gap;
			
			}
		}
	}
}
//堆排序
void _shiftDown(vector<int>	&v, int left, int right,int start)
{
	int n = right - left;
	int i = start;//父节点
	int j = 2 * i + 1;//左子树
	int tmp = v[i];
	while (j < n)
	{
		if (j + 1 < n && v[j] < v[j + 1])
			j++;
		if (tmp < v[j])
		{
			v[i] = v[j];
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			break;
		}
	}
	v[i] = tmp;
}
void HeapSort(vector<int>& v, int left, int right)
{
	//建堆
	int n = right - left;
	int curpos = (n - 1) / 2 + left;
	while (curpos >= left)
	{
		_shiftDown(v, left, right, curpos);
		curpos--;
	}
	//排序
	int end = right - 1;
	while ( end>left )
	{
		Swap(v[left],v[end] );
		_shiftDown(v, left, end, left);
		end--;
	}
}
int main()
{
	vector<int> v = { 49,38,65,97,76,27,49 };
	//ShellSort(v, 0, v.size());
	//HeapSort(v, 0, v.size());
	quickSort(v, 0, v.size());
	for (auto& e : v)
	{
		cout << e << " ";
	}
}
