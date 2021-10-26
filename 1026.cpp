#include<iostream>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        bool x = n > 1 && (n += Sum_Solution(n - 1));
     
        return n;
    }
};
int main()
{
    Solution A;
    cout << A.Sum_Solution(5) << endl;
    return 0;
}