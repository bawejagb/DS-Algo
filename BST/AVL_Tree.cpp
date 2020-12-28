/*
Write a program to implement AVL Tree algorithm.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node{
    int data,height;
    Node *left, *right;
    Node():height{0}, left{NULL}, right{NULL}{};
};

class AVLTree
{
    Node* head;
    Node* insertNode(Node* node, Node* leaf);
    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    void travInorder(Node* node);
    void travPreorder(Node* node);
    void travPostorder(Node* node);
    Node* deleteNode(Node* node, int val);
    Node* predecessor(Node* node);
public:
    AVLTree(): head{NULL}{};
    void insert(int val);
    void Delete(int val);
    void inTraverse();
    void preTraverse();
    void postTraverse();
};

void AVLTree::insert(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    if(!head)
        head = newNode;
    else
        head = AVLTree::insertNode(head, newNode);
}
Node* AVLTree::insertNode(Node* node, Node* leaf)
{
    if(!node)
        return leaf;
    if(node->data > leaf->data)//LEFT
        node->left = AVLTree::insertNode(node->left, leaf);
    else//RIGHT
        node->right = AVLTree::insertNode(node->right, leaf);
    node->height = max(AVLTree::height(node->left), AVLTree::height(node->right)) + 1;
    int balance = AVLTree::getBalance(node);
    if(balance > 1 && node->left->data > leaf->data)
        return AVLTree::rightRotate(node);
    if(balance > 1 && node->left->data < leaf->data)
    {
        node->left = AVLTree::leftRotate(node->left);
        return AVLTree::rightRotate(node);
    }
    if(balance < -1 && node->right->data < leaf->data)
        return AVLTree::leftRotate(node);
    if(balance < -1 && node->right->data > leaf->data)
    {
        node->right = AVLTree::rightRotate(node->right);
        return AVLTree::leftRotate(node);
    }
    return node;
}
int AVLTree::height(Node* node)
{
    if(!node)
        return 0;
    return node->height;
}
int AVLTree::getBalance(Node* node)
{
    return (AVLTree::height(node->left) - AVLTree::height(node->right));
}
Node* AVLTree::rightRotate(Node* node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(AVLTree::height(node->left),AVLTree::height(node->right)) + 1;
    temp->height = max(AVLTree::height(temp->left),AVLTree::height(temp->right)) + 1;
    return temp;
}
Node* AVLTree::leftRotate(Node* node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(AVLTree::height(node->left),AVLTree::height(node->right)) + 1;
    temp->height = max(AVLTree::height(temp->left),AVLTree::height(temp->right)) + 1;
    return temp;
}
void AVLTree::inTraverse()
{
    if(!head)
        cout << "Empty Tree!";
    else
        AVLTree::travInorder(head);
    cout << endl;
}
void AVLTree::preTraverse()
{
    if(!head)
        cout << "Empty Tree!";
    else
        AVLTree::travPreorder(head);
    cout << endl;
}
void AVLTree::postTraverse()
{
    if(!head)
        cout << "Empty Tree!";
    else
        AVLTree::travPostorder(head);
    cout << endl;
}
void  AVLTree::travInorder(Node* node)
{
    if(node->left)
       AVLTree::travInorder(node->left);
    cout << node->data << ' ';
    if(node->right)
        AVLTree::travInorder(node->right);
}
void  AVLTree::travPreorder(Node* node)
{
    cout << node->data << ' ';
    if(node->left)
       AVLTree::travPreorder(node->left);
    if(node->right)
        AVLTree::travPreorder(node->right);
}
void  AVLTree::travPostorder(Node* node)
{
    if(node->left)
       AVLTree::travPostorder(node->left);
    if(node->right)
        AVLTree::travPostorder(node->right);
    cout << node->data << ' ';
}
void AVLTree::Delete(int val)
{
    if(head)
        head = AVLTree::deleteNode(head, val);
    else 
        cout << "Tree is empty!\n";
}
Node* AVLTree::deleteNode(Node* node, int val)
{
    if(node == NULL)
        return node;
    else if(val < node->data)
        node->left = AVLTree::deleteNode(node->left, val);
    else if(val > node->data)
        node->right = AVLTree::deleteNode(node->right, val);
    else if(val == node->data)
    {

        if(!node->left)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if(!node->right)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = AVLTree::predecessor(node->left);
        node->data = temp->data;
        node->left = AVLTree::deleteNode(node->left, temp->data);
    }
    if(node == NULL)
        return node;
    node->height = max(AVLTree::height(node->left), AVLTree::height(node->right)) + 1;
    int balance = AVLTree::getBalance(node);
    if(balance > 1 && AVLTree::getBalance(node->left) >= 0)
        return AVLTree::rightRotate(node);
    if(balance > 1 && AVLTree::getBalance(node->left) < 0)
    {
        node->left = AVLTree::leftRotate(node->left);
        return AVLTree::rightRotate(node);
    }
    if(balance < -1 && getBalance(node->right) <= 0)
        return AVLTree::leftRotate(node);
    if(balance < -1 && getBalance(node->right) > 0)
    {
        node->right = AVLTree::rightRotate(node->right);
        return AVLTree::leftRotate(node);
    }
    return node;
}

Node* AVLTree::predecessor(Node* node)
{
    while(node->right)
        node = node->right;
    return node;
}
main()
{
    AVLTree avt;
    avt.insert(10);
    avt.insert(8);
    avt.insert(6);
    avt.insert(12);
    avt.insert(15);
    avt.insert(19);
    avt.insert(7);
    avt.insert(5);
    avt.insert(3);
    avt.insert(1);
    avt.insert(14);
    avt.insert(17);
    avt.inTraverse();
    avt.preTraverse();
    avt.postTraverse();
    avt.Delete(10);
    avt.inTraverse();
    avt.preTraverse();
    avt.postTraverse();
    return 0;
}