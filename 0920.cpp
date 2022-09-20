#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> num(100);
    int i = 0;
    while (cin >> num[i])
    {
        i++;
    }
    int ans = 0;
    for (int j = 0; j < num.size(); j += 2)
    {
        ans += num[j + 1] - num[j];
    }
    cout << ans << endl;
}
