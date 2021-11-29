#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int now, ans;
        now = 0, ans = INT_MIN;
        for (int i = 0; i < array.size(); i++)
        {
            if (now < 0)
                now = array[i];
            else
            {
                now += array[i];
            }
            ans = max(now, ans);
        }
        return ans;
    }
};
void main()
{
    vector<int> iv = { 1,2,32,3,3 };
    Solution a;
    cout<<a.FindGreatestSumOfSubArray(iv);
}