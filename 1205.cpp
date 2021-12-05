#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
	queue<int>queue1;
	queue<int>queue2;
	MyStack() {

	}
	void push(int x)
	{
		queue2.push(2);
		while (!queue1.empty())
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		swap(queue1, queue2);
	}
	int pop()
	{
		int r = queue1.front();
		queue1.pop();
		return r;
	}
	int top()
	{
		int r = queue1.front();
		return r;
	}
	bool empty()
	{
		return queue1.empty();
	}
};
void main()
{	
	MyStack mystack;
	queue<int>q ;
	vector<int>v = { 1,2,4 };
	for (const auto& e : v)
		q.push(e);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	mystack.push(2);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}