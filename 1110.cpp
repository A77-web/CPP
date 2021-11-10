#include<iostream>
#include<list>
using namespace std;

template<class T>
class Listnode
{
	ListNode(const T& val=T()):_pPre(nullptr),_pNext(nullptr),_val(val)
	{}
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _val;
};
//µü´úÆ÷Àà
template<class T>
class ListIterator
{
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Self;
public:
	ListIterator(PNode pNode=null):_pNode(pNode)
	{}
	T&operator*()
	{
		return _pNode->val;
	}
	T* operator->()
	{
		return &(operator*());
	}
	ListIterator& operator++()
	{
		_pNode = _pNode->_pNext;
		return *this;
	}
	ListIterator operator++(int)
	{
		ListIterator temp(*this);
		_pNode = _pNode->_pNext;
		return temp;
	}
	bool operator!=(const ListIterator& l)
	{
		return _pNode != l.pNode;
	}
	bool operator==(const ListIterator& l)
	{
		return _pNode == l.pNode;
	}
};

