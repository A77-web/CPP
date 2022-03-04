class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        // 结点本身也是其祖先
        if(a == b || a == b / 2)
            return a;
        if(b == a / 2)
            return b;
        // 这里a ！= b 一直运行，先让大的往前走，直到找到为止
        while(a != b)
        {
            if(a > b)
                a = a / 2;
            else
                b = b / 2;
        }
        return a;
    }
};
