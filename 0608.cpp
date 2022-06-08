#include<iostream>
using namespace std;
void _MergeSort(int ar[], int left, int right, int* tmp)
{
	//·Ö½â
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);
	//¹é²¢
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;
	begin2 = mid + 1, end2 = right;
	int k = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[k++] = ar[begin1++];
		else
			tmp[k++] = ar[begin2++];
	}
	while (begin1 <= end1)
		tmp[k++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[k++] = ar[begin2++];
	memcpy(ar + left, tmp + left, sizeof(int) * (right-left+1));
}
void MergeSort(int ar[], int left, int right)
{
	int n = right - left;
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(ar, left, right-1, tmp);
	free(tmp);
}
int main()
{
	int ar[] = { 49,38,65,97,76,27,49 };
	//ShellSort(v, 0, v.size());
	//HeapSort(v, 0, v.size());
	MergeSort(ar, 0, sizeof(ar)/sizeof(ar[0]));
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
}