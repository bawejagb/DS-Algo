/*
Develop a menu driven program demonstrating the following operations 
on a Stack: push(), pop(), isEmpty(), isFull(), display(), and peek().
Note: Use either arrays or linked list to implement stack.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next = NULL;
};

class Stack
{
    Node *head = NULL;
    public:
        void push(int val)
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
        int pop()
        {
            Node *p = head;
            int val = p->data;
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
        int peek()
        {
            return head->data;
        }

};

main()
{
    Stack s1;
    short sel;
    cout << "----Menu----\n"
            "1. Push\n"
            "2. Pop\n"
            "3. Is_Empty\n"
            "4. Is_Full\n"
            "5. Display\n"
            "6. Peek\n"
            "7. Exit\n";
    while (1)
    {
        cout << "\nSelect operation: ";
        cin >> sel;
        switch (sel)
        {
            case 1://Push
            {
                int val;
                cout << "Enter a value to insert: ";
                cin >> val;
                s1.push(val);
                break;
            }
            case 2://Pop
            {
                 if (s1.isEmpty())
                    cout << "Unable to pop as stack is empty!\n";
                else
                    cout << "Poped value is " << s1.pop() << endl;
                break;
            }
            case 3://Is_Empty
            {
                if (s1.isEmpty())
                    cout << "Stack is empty!\n";
                else
                    cout << "Stack is not empty!\n";
                break;
            }
            case 4://Is_Full
            {
                if (s1.isFull())
                    cout << "Stack is Full!\n";
                else
                    cout << "Stack is not Full!\n";
                break;
            }
            case 5://Display
            {
                s1.display();
                break;
            }
            case 6://Peek
            {
                if (s1.isEmpty())
                    cout << "Stack is empty!\n";
                else
                    cout << "Peek value is " << s1.peek() << endl;
                break;
            }
            default://Exit
            {
                exit(0);
            }
        }
    }
    return 0;
}
