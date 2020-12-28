/*
Write a non-recursive function to traverse 
a BST in in-order traversal using stack.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

class BST 
{
    public:
    Node *root = NULL;
        void insert(int val)
        {
            Node *newNode = new Node();
            newNode->data = val;
            if (root == NULL)
                root = newNode;
            else
            {
                Node *temp = root;
                while(1)
                {
                    if(temp->data == val)
                    {
                        cout << "Duplicate data " << val <<
                         " cannot insert!\n";
                        delete newNode;
                        break;
                    }    
                    else if(temp->data > val)
                    {
                        if(temp->left != NULL)
                            temp = temp->left;
                        else
                        {
                            temp->left = newNode;
                            break;
                        }
                    }
                    else
                    {
                        if(temp->right != NULL)
                            temp = temp->right;
                        else
                        {
                            temp->right = newNode;
                            break;
                        }
                    }
                }
            }
        }
};

void inorderTrav(Node* root)
{
    stack <Node*> stk;
    if(!root)
    {
        cout << "Empty tree!\n";
        return;
    }
    Node *temp = root;
    while(temp || !stk.empty())
    {
        if(temp)
        {
            stk.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = stk.top()->right;
            cout << stk.top()->data << ' ';
            stk.pop();
        }
    }
    
    cout << endl;
}

main()
{
    int arr[] = {5,2,10,19,6,1,11,15,3,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    BST bsTree;
    for(int i = 0; i < size; i++)
        bsTree.insert(arr[i]);
    inorderTrav(bsTree.root);
    return 0;
}