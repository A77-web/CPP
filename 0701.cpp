#include <iostream>
using namespace std;
void* memcpy(void* dst, void* src, size_t size)
{
	char* pdst = (char *)dst;
	char* psrc = (char *)src;
	if (dst == NULL || src == NULL)
		return NULL;
	//如果src与dst有重叠 则从后往前进行复制
	if ((src < dst) && (char*)src + size > (char*)dst)
	{
		pdst = (char*)dst + size - 1;
		psrc = (char*)src + size - 1;
		while (size--)
		{
			*pdst-- = *psrc--;
		}
	}
	else
	{
		pdst = (char*)dst ;
		psrc = (char*)src ;
		while (size--)
		{
			*pdst++ = *psrc++;
		}
	}
	return dst;
}
void main()
{
	char buff[1024] = "qwertyui";
	memcpy(buff + 2, buff, 5);
	cout << buff << endl;
}