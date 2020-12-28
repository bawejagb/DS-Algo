/*
Write a program for the evaluation of a Postfix expression

Made By: Gaurav Baweja
*/
#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
	int data;
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
                return 0;
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


int charToInt(string str)
{
    int i = 0, val = 0;
    while(str[i] != '\0')
    {
        val = val*10 + (str[i] - '0');
        i++;
    }
    return val;
}
main()
{
	Stack s1;
    string outString, postfix = "5 6 2 + * 12 4 / -";
    cout << postfix << endl;
    char c;
    int a, b, k, sum = 0;
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        k = 0;
        c = postfix[i];
        outString = "";
        if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == ' ')
        {
            if(c == '^')
            {
                b = s1.pop();
                a = s1.pop();
                sum = pow(a,b);
            }
            else if(c == '*')
            {
                b = s1.pop();
                a = s1.pop();
                sum = a*b;
            }
            else if(c == '/')
            {
                b = s1.pop();
                a = s1.pop();
                sum = a/b;
            }
            else if(c == '+')
            {
                b = s1.pop();
                a = s1.pop();
                sum = a+b;
            }
            else if(c == '-')
            {
                b = s1.pop();
                a = s1.pop();
                sum = a-b;
            }
            else
                continue;
            s1.push(sum);
            
        }
        else
        {
           while (postfix[i] != ' ')
            {
                outString += postfix[i];
                i++;
            }
            outString += '\0';
            s1.push(charToInt(outString));
        }
    }
    cout << "Sum : " << sum;
}
