/*
Write a program to check if a doubly 
linked list of characters is palindrome or not.

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node* next = NULL, *prev = NULL;		
};

struct DoubleLL
{
	Node* head = NULL;	
	void insertAtEnd(char val)
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
bool checkPalindrome(Node* head)
{
	Node *f, *l;
	if (head == NULL)
		return 0;
	f = head;
	for(l = head; l->next != NULL; l = l->next);
	while (f != l && f != l->next)
	{
		if (f->data != l->data)
			return 0;
		f = f->next;
		l = l->prev;
	}
	return 1;
}
main()
{
	DoubleLL list1;
	bool status;
	list1.insertAtEnd('M');
	list1.insertAtEnd('A');
	list1.insertAtEnd('D');
	list1.insertAtEnd('A');
	list1.insertAtEnd('M');
	list1.show();
	status = checkPalindrome(list1.head);
	if (status)
		cout << "It is a palindrome!\n";
	else
		cout << "It is not apalindrome!\n";
	return 0;	
}
