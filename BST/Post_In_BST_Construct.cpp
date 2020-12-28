/*
Given inorder and postorder traversals, construct the BST.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

void inorderTrav(Node *node)
{
    if(node->left)
        inorderTrav(node->left);
    cout << node->data << ' ';
    if(node->right)
        inorderTrav(node->right);
}

Node* newNode(int val)
{
    Node * node = new Node();
    node->data = val;
    return node;
}
Node* post_in_BST(int inorder[], int postorder[], int start, int end)
{
    static int count = 0;
    int i;
    if(end < start)
        return NULL;
    Node *node = newNode(postorder[count]);
    for(i = start; i <= end; i++)
        if(inorder[i] == postorder[count])
            break;
    count++;
    node->right = post_in_BST(inorder, postorder, i+1, end);
    node->left = post_in_BST(inorder, postorder, start, i-1);
    return node;
}

void swap(int &a, int &b)
{
    int c = b;
    b = a;
    a = c;
}
main()
{
    int inorder[] = {2,3,5,8,10,12,15,17};
    int postorder[] = {3,2,8,5,12,17,15,10};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    for(int i = 0; i < size/2; i++)
        swap(postorder[i], postorder[size-i-1]);
    Node* root = post_in_BST(inorder, postorder, 0, size-1);
    cout << "BST - inorder Traversal:\n";
    inorderTrav(root);
    return 0;
}