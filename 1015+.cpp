#include<iostream>
using namespace std;
class my_class {
public:
	//定义了一个将类转化为int的转换函数
	operator int() {
		cout << "convert_to_int" << endl;
		return 1;
	}
};
int main() {
	my_class ;
	int t_a = (int)a;//第一次显式的转换
	cout << a << endl; 
	return 0;
}