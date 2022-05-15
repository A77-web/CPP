class Solution {
public:
    string reverseWords(string s) {
        string s1;
        for(int j=s.size()-1;j>=0;j--)
        {
            if(s[j]==' ')
            continue;
            int i=j;
            while(i>=0&&s[i]!=' ')
            i--;
            s1.append(s.substr(i+1,j-i));
                s1.append(" ");
            j=i;
        }
         if(!s1.empty()) s1.pop_back();
        return s1;
    }
};
