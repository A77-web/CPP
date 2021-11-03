#include<iostream>
#include"SeqList.h"
//#include<list>
using namespace std;


namespace bit_list
{
	//list
	template<typename _Ty>
	class list
	{
	public:
		//ÀàÐÍÝÍÈ¡
		typedef size_t     size_type;
		typedef _Ty        value_type;
		typedef _Ty* pointer_type;
		typedef _Ty& reference_type;
		typedef const _Ty* const_pointer_type;
		typedef const _Ty& const_reference_type;
	public:
		struct _Node;
		typedef struct _Node* _Nodeptr;
		struct _Node
		{
			_Nodeptr _Next, _Prev;
			_Ty _Value;
		};

		struct _Acc
		{
			typedef struct _Node*& _Nodepref;
			typedef _Ty& _Vref;
			static _Nodepref _Next(_Nodeptr _P)
			{
				return _P->_Next;
			}
			static _Nodepref _Prev(_Nodeptr _P)
			{
				return _P->_Prev;
			}
			static _Vref _Value(_Nodeptr _P)
			{
				return _P->_Value;
			}
		};
	public:
		list() :_Head(_Buynode()), _Size(0)
		{}
	public:
		void push_front(const _Ty& _X)
		{}
		void push_back(const _Ty& _X)
		{
			_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
			_Acc::_Value(_S) = _X;

			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;

			_Size++;
		}
	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
		{
			_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		_Nodeptr _Head;
		size_type _Size;
	};
};

int main()
{
	bit_list::list<int> mylist;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);


	return 0;
}
