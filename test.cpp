#include <iostream>
#include <vector>
using namespace std;
void InsertSort(int arry[],int left,int right)
{
    for (int i = left + 1; i < right; ++i)
    {
        int k = left;
        while (arry[i] > arry[k])
            k++;
        int tmp = arry[i];//保存当前插入数据
        for (int j = i; j > k; --j)
            arry[j] = arry[j - 1];
        arry[k] = tmp;
    }
}
int main()
{

    int arry[] = { 6, 2, 5, 6, 8, 1, 9, 3, 4 };
    int n = sizeof(arry) / sizeof(arry[0]);
    InsertSort(arry,0,n);
    for (int i = 0; i < n; i++)
    {
        cout << arry[i];
    }
  
    return 0;
}