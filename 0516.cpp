class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1;
        s1.append(s.substr(n,s.size()-1));
        s1.append(s.substr(0,n));
        return s1;
    }
};
