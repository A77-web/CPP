#include<iostream>
#include<list>
using namespace std;


	//½ÚµãÀà
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _pPre(nullptr), _pNext(nullptr), _val(val)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};
void main()
{
const list<int> mylist;
list<int>::const_iterator cit = mylist.begin();
}