/*
Write a program to check if a linked list 
is Circular Linked List or not

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next = NULL;		
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	return node; 
}

bool checkCircular(Node* head)
{
	bool status = 0;
	Node *t;
	if (head == NULL)
		return 0;
	for (t = head->next; t!=NULL && t != head; t = t->next);
	if (t == NULL)
		status = 0;
	else
		status = 1;
	return status;	
}

main()
{
	bool status;
	Node* head = NULL;
	Node* node1 = newNode(10);
	Node* node2 = newNode(20);
	Node* node3 = newNode(30);
	Node* node4 = newNode(40);
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node1;
	status = checkCircular(head);
	if (status)
		cout << "This is a Circular Linked List!\n";
	else
		cout << "This is not a Circular Linked List!\n";
	return 0;	
}
