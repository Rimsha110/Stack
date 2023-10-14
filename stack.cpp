#include <iostream>
using namespace std;
class Stack
{
private:
	int top;
	int size;
	int* stack;
public:
	Stack()
	{
		top = -1;
		size = 1;
		stack = nullptr;
	}
	Stack(int s)
	{
		size = s;
		top = -1;
		stack = new int[size];
	}
	~Stack()
	{
		if (stack)
		{
			delete[] stack;
			stack = nullptr;
		}
	}
	void push(int val)
	{
		if (isFull())
		{
			resize();
		}
		stack[++top] = val;
	}
	void pop()
	{
		if (!isEmpty())
		{
			--top;
		}
	}
	int top()
	{
		if (!isEmpty())
		{
			return stack[top];
		}
		else
		{
			cout << "Your stack is empty, there is nothing to top! \n";
		}
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == size - 1;
	}
	void resize()
	{
		int* temp = new int[2 * size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = stack[i];
		}
		delete[] stack;
		stack = temp;
		size = 2 * size;
	}
};
int main()
{
	int s;
	cout << "Enter size of stack: ";
	cin >> s;
	while (s <= 0)
	{
		cout << "Enter a non-zero positive size: ";
		cin >> s;
	}
	Stack myStack(s);
	myStack.push(2);
	myStack.push(7);
	myStack.push(9);
	myStack.push(10);
	return 0;
}