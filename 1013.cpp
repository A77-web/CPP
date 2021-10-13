#include<iostream>
using namespace std;
 int call() {
	static int num = 1;
	return num++;
}
int main() {
	for (int i = 0; i < 500; i++) {
		cout << call() << endl;
	}
}