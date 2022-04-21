class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,int> mp;
        for(auto &e :numbers)
        {
            ++mp[e];
        }
        int res=0;
        for(auto [e,occ] :mp)
        {
            if(occ>(numbers.size()/2))
               res=e;
        }
        return res;
    }
};
