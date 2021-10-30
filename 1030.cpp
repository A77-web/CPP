#include<iostream>
using namespace std;
template<typename Type,size_t N>
class Test
{
private:
	Type ar[N];
};
int main()
{
	Test<int, 10>t;
	return 0;
}