#include <iostream>
using namespace std;
class A {
private:
	int a;
public:
	A(int b) :a(b) {
		cout << "构造函数" << endl;
	}
	A(const A& c) {
		a = c.a;
		cout << "拷贝构造函数" << endl;
	}
	~A() {
		cout << "析构函数" << endl;

	}
};
int main() {
	A a(100);
	A b = a;
	return 0;

}