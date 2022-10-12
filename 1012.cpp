#include<iostream>
#include <assert.h>
using namespace std;
char* myStrcpy(char* dest, char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "XXXXXXXXXXXXXXXXXXX";
	char arr2[] = "hello";
	myStrcpy(arr1, arr2);
	printf("%s", arr1);
	printf("%s\n", myStrcpy(arr1, arr2));
	return 0;

}