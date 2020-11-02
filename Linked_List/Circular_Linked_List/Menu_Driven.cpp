/*
Q-1  Develop a menu driven program for the following operations of on a Circular as well as a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be deleted may appear as a head node, last node or a node in between.
(c) Search for a node.

Made By : Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node1 // Node for Doubly Linked List
{
	int data;
	Node1* next = NULL, *prev = NULL;		
};

struct Node2 // Node for Circular Linked List
{
	int data;
	Node2* next = NULL;		
};

class DoubleLL
{
	Node1 *head = NULL;	
	public:
		void insertAtBeginning(int val)
		{
			Node1 *newNode = new Node1();
			newNode->data = val;
			if (head == NULL)
				head = newNode;
			else
			{
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
			}
		}
		void insertAtEnd(int val)
		{
			Node1 *p, *newNode = new Node1();
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
		void insertAfterItem(int ref, int val)
		{
			Node1 *p, *newNode = new Node1();
			newNode->data = val;
			if (head == NULL)
				cout << "List is empty!";
			else
			{
				for(p = head; p!= NULL && p->data != ref; p = p->next);
				if (p != NULL)
				{
					newNode->next = p->next;
					if(p->next != NULL)
						p->next->prev = newNode;
					p->next = newNode;
				}
				else
					cout << ref << " node not found in list!\n";
			}
		}
		void insertBeforeItem(int ref, int val)
		{
			if (head == NULL)
				cout << "List is empty!";
			else
			{
				Node1 *p, *newNode = new Node1();
				newNode->data = val;
				for(p = head; p!= NULL && p->data != ref; p = p->next);
				if (p != NULL)
				{
					newNode->next = p;
					if(p->prev != NULL)
						p->prev->next = newNode;
					else
						head = newNode;
					p->prev = newNode;
				}
				else
					cout << ref << " node not found in list!\n";
			}
		}
		void deleteNode(int val)
		{
			if (head == NULL)
				cout << "List is empty!\n";
			else
			{
				Node1 *p;
				for (p = head; p != NULL && p->data != val; p = p->next);
				if (p != NULL)
				{
					if (p->prev != NULL)
						p->prev->next = p->next;
					else
						head = p->next;
					if (p->next != NULL)
						p->next->prev = p->prev;
					delete p;
				}
				else
					cout << val << " node not found in List!\n";
			}
		}
		void searchNode(int val)
		{
			if (head == NULL)
				cout << "List is empty!\n";
			else
			{
				Node1 *p;
				for (p = head; p != NULL && p->data != val; p = p->next);
				if (p != NULL)
					cout << val << " node is present in list!\n";
				else
					cout << val << " node is not present in List!\n";
			}
		}
		void show()
		{
			if (head == NULL)
				cout << "List is empty!\n";
			else
			{
				Node1 *p;
				for (p = head; p != NULL; p = p->next)
					cout << p->data << " ";
				cout << endl;
			}
		}
};

class CircularLL
{
	Node2 *last = NULL;
	public:
		void insertAtBeginning(int val)
		{
			Node2 *newNode;
			newNode = new Node2();
			newNode->data = val;
			if (last == NULL)
			{
				last = newNode;
				newNode->next = newNode;
			}
			else
			{
				newNode->next = last->next;
				last->next = newNode;
			}
		}
		void insertAtEnd(int val)
		{
			Node2 *newNode;
			newNode = new Node2();
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
		void insertAfterItem(int ref, int val)
		{
			
			if (last == NULL)
				cout << "List is empty!";
			else 
			{
				Node2 *newNode, *p;
				newNode = new Node2();
				newNode->data = val;
				int flag = 0;
				p = last;
				do
				{
					if (p->data == ref)
					{
						newNode->next = p->next;
						p->next = newNode;
						flag = 1;
						break;
					}
					p = p->next;
				}
				while (p != last);
				if (flag == 0)
					cout << ref << " is not present in list!\n";
			}
		}
		void insertBeforeItem(int ref, int val)
		{
			if (last == NULL)
				cout << "List is empty!\n";
			else 
			{
				Node2 *newNode, *prev, *p = last;
				int flag = 0;
				newNode = new Node2();
				newNode->data = val;
				prev = p;
				p = last->next;
				do
				{
					if (p->data == ref)
					{
						newNode->next = prev->next;
						prev->next = newNode;
						flag = 1;
						break;
					}
					prev = p;
					p = p->next;
				}
				while (p != last->next);
				if (flag == 0)
					cout << ref << " is not present in list!\n";
			}
		}
		void deleteNode(int ref)
		{
			if (last == NULL)
				cout << "List is empty!\n";
			else if (last->next == last && last->data == ref)
			{
				delete last;
				last = NULL;
			}
			else
			{
				int flag = 0;
				 Node2 *p, *prev;
				 prev = last;
				 p = last->next;
				 do
				 {
				 	if (p->data == ref)
				 	{
				 		prev->next = p->next;
				 		delete p;
				 		flag = 1;
				 		break;
					}
					prev = p;
					p = p->next;
				 }
				 while (p != last->next);
				 if (flag == 0)
					cout << ref << " is not present in list!\n";
			}
		}
		void searchNode(int val)
		{
			if (last == NULL)
				cout << "List is empty!\n";
			else
			{
				int flag = 0;
				Node2 *p = last;
				do
				{
					if (p->data == val)
					{
						cout << val << " is present in list!\n";
						flag = 1;
						break;
					}
					p = p->next;
				}
				while(p != last);
				if (flag == 0)
					cout << val << " is not present in list!\n";
			}
		}
		void show()
		{
			if (last == NULL)
				cout << "List is empty!\n";
			else
			{
				Node2 *p = last->next;
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

main()
{
	cout << "--- MENU ---\n1. Doubly Linked List\n"
			"2. Circular Linked List\n";
	short opt, select;
	DoubleLL list1;
	CircularLL list2;
	while (1)
	{
		cout << "\nSelect operation: ";
		cin >> opt;
		if (opt == 1)
		{
			cout << "Doubly Linked List - \n";
			break;
		}
		else if(opt == 2)
		{
			cout << "Circular Linked List - \n";
			break;
		}
		else
			cout << "Wrong input!\n";
	}
	
	cout << "--- MENU ---\n1. Insertion at the beginning\n"
			"2. Insertion at the end\n"
			"3. Insertion after node\n"
			"4. Insertion before node\n"
			"5. Deletion of a specific node\n"
			"6. Search for a node value\n"
			"7. Display all the nodes\n";
	
	while (1)
	{
		cout << "\nSelect operation: ";
		cin >> select;
		switch (select)
		{
			case 1:// Inserting at begnning
				{
					int value;
					cout << "Enter node value to add in beginning of list : ";
					cin >> value;
					if (opt == 1)
						list1.insertAtBeginning(value);
					else
						list2.insertAtBeginning(value);
					break;
				}
			case 2:// Insertion at the end.
				{
					int value;
					cout << "Enter node value to add in end of list: ";
					cin >> value;
					if (opt == 1)
						list1.insertAtEnd(value);
					else
						list2.insertAtEnd(value);
					break;
				}
			case 3:// Insertion after node
				{
					int value, refVal;
					cout << "Enter reference node value: ";
					cin >> refVal;
					cout << "Enter value to add after ref node: ";
					cin >> value;
					if (opt == 1)
						list1.insertAfterItem(refVal, value);
					else
						list2.insertAfterItem(refVal, value);
					break;
				}
			case 4:// Insertion before node
				{
					int value, refVal;
					cout << "Enter reference node value: ";
					cin >> refVal;
					cout << "Enter value to add before ref. node: ";
					cin >> value;
					if (opt == 1)
						list1.insertBeforeItem(refVal, value);
					else
						list2.insertBeforeItem(refVal, value);
					break;
				}
			case 5:// Deletion of a specific node value
				{
					int value;
					cout << "Enter node value to delete from a list: ";
					cin >> value;
					if (opt == 1)
						list1.deleteNode(value);
					else
						list2.deleteNode(value);
					break;
				}
			case 6:// Search for a node and display its position from head
				{
					int value;
					cout << "Enter node value to search position in a list: ";
					cin >> value;
					if (opt == 1)
						list1.searchNode(value);
					else
						list2.searchNode(value);
					break;
				}
			case 7:// Display all the node values.
				{
					if (opt == 1)
						list1.show();
					else
						list2.show();
					break;
				}
			default:// EXIT
				{
					exit(0);
					break;
				}
		}
	}
	return 0;
}

