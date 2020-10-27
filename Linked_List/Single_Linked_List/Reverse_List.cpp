/*
Qn Write a program to reverse a linked list.

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next = NULL;		
};

class LinkedList
{
	Node *head = NULL;
	public:

	void show()
	{
		Node *node = head;
		for (node; node != NULL; node = node->next)
			cout << node->data << " ";
		cout << endl;
	}
	
	void insertAtEnd(int val)
	{
		Node *newNode = new Node();
		newNode->data = val;
		if (head == NULL)
			head = newNode;
		else
		{
			Node *temp;
			for (temp = head; temp->next != NULL; temp = temp->next);
			temp->next = newNode;
		}
	}
	void reverse()
	{
		Node *prev, *next, *present = head;
		prev = next = NULL;
		while (present != NULL)
		{
			next  = present->next;
			present->next = prev;
			prev = present;
			present = next;
		}
		head = prev;
	}
};

main()
{
	LinkedList list1;
	for (int i = 1; i < 10; i++)
		list1.insertAtEnd(i*10);
	cout << "Linked List:\n";
	list1.show();
	cout << "Reverse Linked list:\n";
	list1.reverse();
	list1.show();
	return 0;
}

