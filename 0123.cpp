#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Type>
class AVL;

template<class Type>
class AVLNode
{
	friend class AVL<Type>;
public:
	AVLNode(Type d = Type(), AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr)
		: data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode* leftChild;
	AVLNode* rightChild;
	int      bf; //ƽ������ -1 0 1
};

template<class Type>
class AVL
{
public:
	AVL() : root(nullptr)
	{}
public:
	void Insert(const Type& v)
	{
		Insert(root, v);
	}
protected:
	void Insert(AVLNode<Type>*& t, const Type& v);
protected:
	void RotateR(AVLNode<Type>*& ptr);
	void RotateL(AVLNode<Type>*& ptr);
	void RotateLR(AVLNode<Type>*& ptr);
	void RotateRL(AVLNode<Type>*& ptr);
private:
	AVLNode<Type>* root;
};

/////////////////////////////////////////////////////////////
template<class Type>
void AVL<Type>::RotateR(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subR = ptr;
	ptr = subR->leftChild;
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;

	ptr->bf = subR->bf = 0;
}

template<class Type>
void AVL<Type>::RotateL(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL = ptr;
	ptr = subL->rightChild;

	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	ptr->bf = subL->bf = 0;
}

template<class Type>
void AVL<Type>::RotateRL(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL, * subR;
	subL = ptr;
	subR = ptr->rightChild;
	ptr = subR->leftChild;

	//����ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//����ƽ������
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	//����ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//����ƽ������
	if (ptr->bf <= 0)
		subL->bf = 0;
	else
		subL->bf = -1;
}


template<class Type>
void AVL<Type>::RotateLR(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL, * subR;
	subL = ptr->leftChild;
	subR = ptr;
	ptr = subL->rightChild;

	//����ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;
	//����subL��bf
	if (ptr->bf <= 0)
		subL->bf = 0;
	else
		subL->bf = -1;

	//����ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;
	//����subR��bf
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;
}

///////////////////////////////////////////////////////////
template<class Type>
void AVL<Type>::Insert(AVLNode<Type>*& t, const Type& v)
{
	//1 ����BST�������ڵ�
	AVLNode<Type>* pr = nullptr;
	AVLNode<Type>* p = t;

	stack<AVLNode<Type>*> st;
	while (p != nullptr)
	{
		if (v == p->data)
			return;

		pr = p;
		st.push(pr);

		if (v < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(v);
	if (pr == nullptr) //��ʱ����Ľڵ�Ϊ���ڵ�
	{
		t = p;
		return;
	}
	if (v < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//2 ����ƽ��	
	while (!st.empty())
	{
		pr = st.top();
		st.pop();

		if (pr->leftChild == p)
			pr->bf--;
		else
			pr->bf++;

		if (pr->bf == 0)
			break;

		if (pr->bf == 1 || pr->bf == -1)
			p = pr; //���Ų����·�����ϻ���
		else
		{
			//��ƽ�� |bf|==2
			if (pr->bf > 0)
			{
				if (p->bf > 0)     //   \ 
				{
					//cout<<"RotateL"<<endl;
					RotateL(pr);
				}
				else              //  >
				{
					//cout<<"RotateRL"<<endl;
					RotateRL(pr);
				}
			}
			else
			{
				if (p->bf < 0) //   / 
				{
					//cout<<"RotateR"<<endl;
					RotateR(pr);
				}
				else          //  <
				{
					//cout<<"RotateLR"<<endl;
					RotateLR(pr);
				}
			}
			break;
		}
	}

	//�������ӽڵ�
	if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type>* ppr = st.top();
		if (ppr->data > pr->data)
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}
}

int main()
{
	vector<int> iv = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//vector<int> iv = {16, 30, 20};
	AVL<int> avl;

	//for(const auto &e : iv)
	for (int i = 0; i < iv.size(); ++i)
	{
		avl.Insert(iv[i]);
	}
	return 0;
}