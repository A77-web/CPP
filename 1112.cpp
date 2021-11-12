#include<iostream>
//#include<list>
using namespace std;

namespace bit
{
	//节点类
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

	/////////////////////////////////////////////////////
	//迭代器类
	template<class T>
	class list;

	template<class T>
	class ListIterator
	{
		friend class list<T>;
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> Self;
	public:
		ListIterator(PNode pNode = nullptr) : _pNode(pNode)
		{}
		T& operator*()
		{
			return _pNode->_val;
		}
		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)
		{
			return _pNode != l._pNode;
		}
	private:
		PNode _pNode;
	};

	/////////////////////////////////////////////////////
	//链表类
	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T> iterator;
		typedef const ListIterator<T> const_iterator;
	public:
		list()
		{
			CreateHead();
		}
	public:
		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		const_iterator begin()const
		{
			return iterator(_pHead->_pNext);
		}
		const_iterator end()const
		{
			return iterator(_pHead);
		}
	public:
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
	public:
		size_t size()const
		{
			size_t count = 0;
			PNode p = _pHead->_pNext;
			while (p != _pHead)
			{
				count++;
				p = p->_pNext;
			}
			return count;
		}
		bool empty()const
		{
			return size() == 0;
		}
	public:
		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}

	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}

	private:
		PNode _pHead;
	};
};
void main()
{
	bit::list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_front(5);
	mylist.push_front(6);
	mylist.push_front(7);
	mylist.push_front(8);
	cout << mylist.size() << endl;

	bit::list<int> youlist;

	youlist = mylist;
}
