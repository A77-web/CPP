class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        int leng = gifts.size()/2;
        for(int i=0; i<gifts.size(); ++i)
        {
            //count(first,last,value);统计容器中value元素的个数
            //first是容器的首迭代器，last是容器的末迭代器，value是询问的元素。
            if( count(gifts.begin(),gifts.end(),gifts[i]) > leng )
                return gifts[i];
        }
        return 0;
    }
};
