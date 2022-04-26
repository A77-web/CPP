class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(auto e: s)
        {
            if(isalnum(e))
            {
                s1.push_back(tolower(e));
            }
        }
        int left=0,right=s1.size()-1;
        while(left<right)
        {
            if(s1[left]!=s1[right])
            {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
