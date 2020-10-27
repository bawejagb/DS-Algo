/*
Qn Write a program to find the middle of a linked list.

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
	
	void midNode()
	{
		Node *p1, *p2;
		for(p1 = p2 = head; p1 != NULL && p2 != NULL && p2->next != NULL;
			p1 = p1->next )
			p2 = p2->next->next;
		if (p1 == NULL)
			cout << "List is empty!\n";
		else
			cout << "Middle node value is " << p1->data;
	}
};

main()
{
	LinkedList list1;
	for (int i = 1; i < 10; i++)
		list1.insertAtEnd(i*10);
	cout << "Linked List:\n";
	list1.show();
	list1.midNode();
	return 0;
}

