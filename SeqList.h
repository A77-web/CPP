#include<iostream>
using namespace std;

//2019
//
template<typename Type>
class SeqList
{
public:
	SeqList(int sz);
	~SeqList();
public:
	void push_back(const Type& x);
	void show()const;
private:
	Type* base;
	size_t capacity;
	size_t size;
};

template<typename Type>
SeqList<Type>::SeqList(int sz)
{
	capacity = sz;
	base = new Type[capacity];
	size = 0;
}

template<typename Type>
SeqList<Type>::~SeqList()
{
	delete[]base;
	base = nullptr;
	capacity = size = 0;
}

template<typename Type>
void SeqList<Type>::push_back(const Type& x)
{
	base[size++] = x;
}

template<typename Type>
void SeqList<Type>::show()const
{
	for (int i = 0; i < size; ++i)
		cout << base[i] << " ";
	cout << endl;
}
