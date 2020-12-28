/*
Write a program that checks if an expression has balanced parentheses.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;
struct Node
{
	char data;
	Node *next;
};

class Stack
{
	Node *head = NULL;
	public:
		bool isEmpty()
		{
			if(head == NULL)
				return 1;
			return 0;
		}
		bool isFull()
        {
            Node* p = new Node();
            if (p != NULL)
            {
                delete p;
                return 0;
            }
            else
                return 1;
        }
		void push(char val)
		{
			if (this->isFull())
				cout << "Unable to add as Stack will overflow!";
			else
			{
				Node *newNode = new Node();
				newNode->data = val;
				newNode->next = head;
				head = newNode;
			}
		}
		int pop()
		{
            if (this->isEmpty())
                return 0;
			char val;
			Node *p = head;
			head = head->next;
			val = p->data;
			delete p;
			return val;
		}
		int peek()
		{
            if (this->isEmpty())
                return '\0';
			return head->data;
		}
		void display()
		{
			if (head == NULL)
				cout << "Stack is Empty!";
			else
			{
				Node *p;
				for(p = head; p != NULL; p = p->next)
					cout << p->data << ' ';
			}
			cout << endl;
		}
};

main()
{
    Stack s1;
    string pt = "{([])}(([{}]))[]";
    bool bal = 1;
    cout << pt << endl;
    for(int i = 0; pt[i] != '\0'; i++)
    {
        if(pt[i] == '[')
            s1.push('[');
        else if(pt[i] == '{')
            s1.push('{');
        else if(pt[i] == '(')
            s1.push('(');
        else if(pt[i] == ']')
        {
            if(s1.peek() == '[')
                s1.pop();
            else
            {
                bal = 0;
                break;
            }
        }
        else if(pt[i] == '}')
        {
            if(s1.peek() == '{')
                s1.pop();
            else
            {
                bal = 1;
                break;
            }
        }
        else if(pt[i] == ')')
        {
            if(s1.peek() == '(')
                s1.pop();
            else
            {
                bal = 1;
                break;
            }
        }
    }
    if(bal && s1.isEmpty())
        cout << "This expression is a balanced parentheses.";
    else
        cout << "This expression is not a balanced parentheses.";
    return 0;
}