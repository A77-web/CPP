#include<iostream>
using namespace std;
class Solution {
public:
    int Sum_Solution(int n) {
        bool x = n > 1 && (n += Sum_Solution(n - 1));
     
        return n;
    }
};
