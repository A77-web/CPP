#include<iostream>
#include<vector>
#include < unordered_map >
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> mp;
        for (const int val : numbers) ++mp[val];
        for (const int val : numbers) {
            if (mp[val] > numbers.size() / 2) return val;
        }
        return 0;
    }
};  
void main()
{
    vector<int>iv={2,2,2,2,2,4,4,4,4};
    Solution a;
    cout << a.MoreThanHalfNum_Solution(iv);

}