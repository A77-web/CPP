#include<iostream>
using namespace std;
void test(){
	int a = 1;
	int& b = a;
	cout << "a:address->" << &a << endl;
	cout << "b:address->" << &b << endl;
	
}
int main() {
	test();
	return 0;
}
