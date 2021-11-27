#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //≥ı ºªØ
        int len = s.length();
        int i = 0;
        while (i < len)
        {
            int start = i;
            while (i < len && s[i] != ' ')
            {
                i++;
            }
            int left = start, right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < len && s[i] == ' ')
            {
                i++;
            }
        }
        return s;
    }
};
void main()
{
    Solution a;
    string ret=a.reverseWords("Let's take LeetCode contest");
    cout << ret;

}