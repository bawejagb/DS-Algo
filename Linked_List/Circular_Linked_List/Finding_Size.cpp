/*
Q-3(b). Write a program to find size of Circular Linked List.

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next = NULL;		
};

struct CircularLL
{
	Node *last = NULL;
	void insertAtEnd(int val)
	{
		Node *newNode;
		newNode = new Node();
		newNode->data= val;
		if (last == NULL)
		{
			last = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = last->next;
			last->next = newNode;
			last = newNode;
		}
	}
	void show()
	{
		if (last == NULL)
			cout << "List is empty!\n";
		else
		{
			Node *p = last->next;
			do
			{
				cout << p->data << " ";
				p = p->next;
			}
			while(p != last->next);
			cout << endl;
		}
	}
};
int size(Node * last)
{
	Node *p;
	if (last == NULL)
		return 0;
	int count = 1;
	for(p = last->next; p != last; p = p->next)
		count++;
	return count;
}

main()
{
	CircularLL list1;
	for (int i = 1; i < 10; i++)
		list1.insertAtEnd(i*10);
	list1.show();
	cout << "Size of list: " << size(list1.last);
	return 0;	
}
