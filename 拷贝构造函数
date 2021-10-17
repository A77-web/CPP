class Rect
{
public:
    Rect()      // 构造函数，计数器加1
    {
        count++;
    }
    Rect(const Rect& r)   // 拷贝构造函数
    {
        width = r.width;
        height = r.height;
        count++;          // 计数器加1
    }
    ~Rect()     // 析构函数，计数器减1
    {
        count--;
    }
    static int getCount()   // 返回计数器的值
    {
        return count;
    }
private:
    int width;
    int height;
    static int count;       // 一静态成员做为计数器
};
