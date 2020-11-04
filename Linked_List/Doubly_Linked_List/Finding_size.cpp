/*
Q-3(a). Write a program to find size of Doubly Linked List.

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next = NULL, *prev = NULL;		
};

struct DoubleLL
{
	Node* head = NULL;	
	void insertAtEnd(int val)
	{
		Node *p, *newNode = new Node();
		newNode->data = val;
		if (head == NULL)
			head = newNode;
		else
		{
			for(p = head; p->next != NULL; p = p->next);
			p->next = newNode;
			newNode->prev = p;
		}
	}
	void show()
	{
		if (head == NULL)
			cout << "List is empty!\n";
		else
		{
			Node *p;
			for (p = head; p != NULL; p = p->next)
				cout << p->data << " ";
			cout << endl;
		}
	}
};
int size(Node * head)
{
	Node *p;
	int count = 0;
	for(p = head; p != NULL; p = p->next)
		count++;
	return count;
}

main()
{
	DoubleLL list1;
	for (int i = 1; i < 10; i++)
		list1.insertAtEnd(i*10);
	list1.show();
	cout << "Size of list: " << size(list1.head);
	return 0;	
}
