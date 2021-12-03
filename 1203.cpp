#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
void main()
{
    Solution a;
    vector<vector<int>> ret=a.generate(8);
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout << ret[i][j];
         
        }
        cout << endl;
    }
}