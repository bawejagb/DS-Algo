/*
Write a program to check if a linked list 
is Circular Linked List or not
Method 2
Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next = NULL;		
};

struct Node1
{
	Node *present = NULL;
	Node1 *next = NULL;		
};

Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	return node; 
}

Node1* newNode1(Node* p)
{
	Node1* node = new Node1();
	node->present = p;
	return node; 
}

bool checkCircular(Node* head)
{
	Node *p;
	bool status = 0;
	Node1 *prev, *t, *temp;
	temp = t = prev = NULL;
	for(p = head; p!=NULL; p = p->next)
	{
		if (temp == NULL)
		{
			temp = newNode1(p);
			prev = temp;
		}
		else
		{
			if(p == temp->present)
			{
				status = 1;
				break;
			}
			for(t = temp->next; t != NULL; t = t->next)
			{
				if (p == t->present)
					break;
				prev = t;
			}
			if (t != NULL)
				break;
			else
				prev->next = newNode1(p);
		}
	}
	while(temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		delete prev;
	}
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
	node4->next = node3;
	status = checkCircular(head);
	if (status)
		cout << "This is a Circular Linked List!\n";
	else
		cout << "This is not a Circular Linked List!\n";
	return 0;	
}
