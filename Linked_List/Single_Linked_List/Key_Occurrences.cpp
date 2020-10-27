/*
Qn  Write a program to count the number of occurrences 
of a given key in a singly linked list and then delete 
all the occurrences. For example, if given linked list is 
1->2->1->2->1->3->1 and given key is 1, then output should 
be 4. After deletion of all the occurrences of 1, the 
linked list is 2->2->3.

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
	
	int occCount(int val)
	{
		int count = 0;
		Node *node;
		for(node = head; node != NULL; node = node->next)
			 if (node->data == val)
				count++;
		return count;
	}
	
	void deleteNode(int val)
	{
		Node *temp, *prev = NULL;
		for (temp = head; temp != NULL && temp->data != val;
		 temp = temp->next)
		 prev = temp;
		if (temp == NULL)
			cout << "Node is not present in list!\n";
		else if (prev == NULL)
		{
			head = head->next;
			delete temp;
		}
		else
		{
			prev->next = temp->next;
			delete temp;
			}
	}
};

main()
{
	int count, delVal = 1;
	LinkedList list1;
	list1.insertAtEnd(1);
	list1.insertAtEnd(2);
	list1.insertAtEnd(1);
	list1.insertAtEnd(2);
	list1.insertAtEnd(1);
	list1.insertAtEnd(3);
	list1.insertAtEnd(1);
	cout << "Linked List:\n";
	list1.show();
	count = list1.occCount(delVal);
	cout << "Occurrence of " << delVal 
	<< " value in list is " << count << endl;
	for (int i = 1; i <= count; i++)
		list1.deleteNode(delVal);
	cout << "List After Deletion of occurrences value "<< delVal << " :\n";
	list1.show();
	return 0;
}

