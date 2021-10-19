class Student //声明学生类 
{
  private: //声明以下为私有的 
    int number; //学号 
    char name[10];//姓名 
    char sex; //性别 
  public: //声明以下为共有的 
    inline void print_info() //在类外定义打印函数 
    {
      cout<<number<<endl;
      cout<<name<<endl;
      cout<<sex<<endl;
    }
};
