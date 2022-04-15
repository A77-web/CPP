class Solution {
public:
    vector<int> printNumbers(int n) {
        if(n<=0)
        return vector<int>(0) ;
        vector<int> res;
        int num=1;
        for(int i=1;i<=n;i++)
        num*=10;
        for(int j=1;j<num;j++)
        res.push_back(j);
        return res;
    }
};
