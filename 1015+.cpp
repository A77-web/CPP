#include<iostream>
using namespace std;
class my_class {
public:
	//������һ������ת��Ϊint��ת������
	operator int() {
		cout << "convert_to_int" << endl;
		return 1;
	}
};
int main() {
	my_class ;
	int t_a = (int)a;//��һ����ʽ��ת��
	cout << a << endl; 
	return 0;
}