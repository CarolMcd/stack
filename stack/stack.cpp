// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

/*
* Node Declaration
*/
struct node
{
	int info;
	struct node *link;
}*top;


struct stack
{

	node *add(node *, int);
	node *remove(node *);
	void init(node *);
	stack()
	{
		top = NULL;
	}
};

/*
* Main: Contains Menu
*/
int main()
{
	int choice, item;
	stack sl;
	while (1)
	{
		cout << "\n-------------" << endl;
		cout << "Operations on Stack" << endl;
		cout << "\n-------------" << endl;
		cout << "1.Push Element into the Stack" << endl;
		cout << "2.Pop Element from the Stack" << endl;
		cout << "3.Traverse the Stack" << endl;
		cout << "4.Quit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter value to be pushed into the stack: ";
			cin >> item;
			top = sl.add(top, item);
			break;
		case 2:
			top = sl.remove(top);
			break;
		case 3:
			sl.init(top);
			break;
		case 4:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}

/*
* Push Element into the Stack
*/
node *stack::add(node *top, int item)
{
	node *tmp;
	tmp = new (struct node);
	tmp->info = item;
	tmp->link = top;
	top = tmp;
	return top;
}

/*
* Pop Element from the Stack
*/
node *stack::remove(node *top)
{
	node *tmp;
	if (top == NULL)
		cout << "Stack is Empty" << endl;
	else
	{
		tmp = top;
		cout << "Element Popped: " << tmp->info << endl;
		top = top->link;
		delete(tmp);
	}
	return top;
}

/*
* Traversing the Stack
*/
void stack::init(node *top)
{
	node *ptr;
	ptr = top;
	if (top == NULL)
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Stack elements :" << endl;
		while (ptr != NULL)
		{
			cout << ptr->info << endl;
			ptr = ptr->link;
		}
	}
}