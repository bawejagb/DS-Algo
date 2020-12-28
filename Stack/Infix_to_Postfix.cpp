/*
Write a program to convert an Infix expression
 into a Postfix expression.

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

short priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else 
        return 0;
}

main()
{
	Stack s1;
    string postfix, infix = "A+(B*C-(D/E^F)*G)*H";
    cout << infix << endl;
    int k = 0;
    char p;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        p = infix[i];
        //cout << p;
        if (p == '(')
            s1.push(p);
        else if (p == ')')
        {
            char t;
            while(s1.peek() != '(')
                postfix += s1.pop();
            s1.pop();
        }
        else if (p == '*' || p == '/' || p == '+' || p == '-' || p == '^')
        {
            while (priority(s1.peek()) >= priority(p))
                postfix += s1.pop();
            s1.push(p);
        }
        else
            postfix += p;

    }
    while(!s1.isEmpty())
        postfix += s1.pop();

    postfix  += '\0';
    cout << postfix;
}
