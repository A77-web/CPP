#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef enum { BLACK = 0, RED = 1 }Color_Type;

template<class Type>
class RBTree;

template<class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode(const Type& d = Type())
		:data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr), color(RED)
	{}
	~RBNode()
	{}
private:
	Type    data;
	RBNode* leftChild;
	RBNode* rightChild;
	RBNode* parent;
	Color_Type color;
};

template<class Type>
class RBTree
{
public:
	RBTree() :Nil(_Buynode()), root(Nil)
	{
		Nil->parent = Nil->leftChild = Nil->rightChild = nullptr;
		Nil->color = BLACK;
	}
public:
	void Insert(const Type& v)
	{
		Insert(root, v);
	}
	void Remove(const Type& key)
	{
		Remove(root, key);
	}
protected:
	void Insert_Fixup(RBNode<Type>*& t, RBNode<Type>* x);
	void Insert(RBNode<Type>*& t, const Type& v);
protected:
	void RightRotate(RBNode<Type>*& t, RBNode<Type>* p);
	void LeftRotate(RBNode<Type>*& t, RBNode<Type>* p);
protected:
	RBNode<Type>* _Buynode(const Type& v = Type())
	{
		RBNode<Type>* s = new RBNode<Type>(v);
		s->leftChild = s->rightChild = Nil;
		return s;
	}
private:
	RBNode<Type>* Nil;
	RBNode<Type>* root;
};

template<class Type>
void RBTree<Type>::LeftRotate(RBNode<Type>*& t, RBNode<Type>* p)
{
	RBNode<Type>* s = p->rightChild;
	p->rightChild = s->leftChild;
	if (s->leftChild != Nil)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if (p->parent == Nil)
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;
}

template<class Type>
void RBTree<Type>::RightRotate(RBNode<Type>*& t, RBNode<Type>* p)
{
	RBNode<Type>* s = p->leftChild;
	p->leftChild = s->rightChild;
	if (s->rightChild != Nil)
		s->rightChild->parent = p;
	s->parent = p->parent;
	if (p->parent == Nil)
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->rightChild = p;
	p->parent = s;
}
/////////////////////////////////////////////////////////////////

template<class Type>
void RBTree<Type>::Insert(RBNode<Type>*& t, const Type& v)
{
	//1 ����BST�������ڵ�
	RBNode<Type>* x = t, * pr = Nil;
	while (x != Nil)
	{
		if (v == x->data)
			return;

		pr = x;

		if (v < x->data)
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	x = _Buynode(v);
	if (pr == Nil) //˵������Ľڵ�Ϊ��һ�����ڵ�
	{
		t = x;
		t->parent = Nil;
	}
	else if (v < pr->data)
		pr->leftChild = x;
	else
		pr->rightChild = x;
	x->parent = pr;

	//2 ����ƽ��
	Insert_Fixup(t, x);
}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBNode<Type>*& t, RBNode<Type>* x)
{
	while (x->parent->color == RED)
	{
		//��ƽ��
		RBNode<Type>* s;
		if (x->parent == x->parent->parent->leftChild)
		{
			//���֧
			s = x->parent->parent->rightChild;
			//״����
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				s->color = BLACK;
				x = x->parent->parent;
			}
			else
			{
				//״����
				if (x == x->parent->rightChild)  // <
				{
					x = x->parent;
					LeftRotate(t, x);
				}
				//״��һ
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RightRotate(t, x->parent->parent);
			}
		}
		else
		{
			//�ҷ�֧
			s = x->parent->parent->leftChild;

			//״����
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				s->color = BLACK;
				x = x->parent->parent;
			}
			else
			{
				//״����
				if (x == x->parent->leftChild)
				{
					x = x->parent;
					RightRotate(t, x);
				}
				//״��һ
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				LeftRotate(t, x->parent->parent);
			}
		}
	}
	t->color = BLACK;
}


///////////////////////////////////////////////////////////////////
int main()
{
	vector<int> iv = { 10, 7,  8, 15, 5, 6, 11, 13, 12 };
	RBTree<int> rb;

	for (int i = 0; i < iv.size(); ++i)
	{
		rb.Insert(iv[i]);
	}

	return 0;
}