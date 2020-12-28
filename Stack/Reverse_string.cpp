/*
Given a String, Reverse it using STACK. 
For example “data structure” should be output as “erutcurts atad.”

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node* next = NULL;
};

class Stack
{
    Node *head = NULL;
    public:
        void push(char val)
        {
            if (this->isFull())
            {
                cout << "Unable to insert element as Stack is Full!\n";
                return;
            }
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = head;
            head = newNode;
        }
        char pop()
        {
            Node *p = head;
            char val = p->data;
            p = head;
            head = head->next;
            delete p;
            return val;
        }
        bool isEmpty()
        {
            if(head == NULL)
                return 1;
            else
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
        void display()
        {
            if(this->isEmpty())
            {
                cout << "Stack is empty!\n";
                return;
            }
            Node *p;
            for(p = head; p != NULL; p = p->next)
                cout << p->data << ' ';
            cout << endl;
        }
        char peek()
        {
            return head->data;
        }
};

main()
{
    Stack stack1;
    string s2, s1 = "data structure";
    cout << "Original string: " << s1 << endl;
    for (int i = 0; s1[i] != '\0'; i++)
        stack1.push(s1[i]);
    while(!stack1.isEmpty())
        s2 = s2 + stack1.pop();
    s2 = s2 + '\0';
    cout << "Reverse String: " << s2 << endl;
    return 0;
}
