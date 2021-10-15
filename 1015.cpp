#include<iostream>
using namespace std;
class Test {
private:
	int x;
	int y;
public:
	void setX(int a) {
		x = a;
	}
	void setY(int b) {
		y = b;
	}
	void getXY(int* px, int* py) {
		*px = x;
		*py = y;
			
	}
};
int main() {
	Test p1;
	p1.setX(1);
	p1.setY(9);
	int a, b;
	p1.getXY(&a, &b);
	cout << a << '\n' << b << endl;
	return 0;
}