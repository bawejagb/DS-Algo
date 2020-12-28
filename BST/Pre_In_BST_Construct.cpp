/*
Given preorder and inorder traversals, construct the BST.

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
Node* pre_in_BST(int inorder[], int preorder[], int start, int end)
{
    static int count = 0;
    int i;
    if(end < start)
        return NULL;
    Node *node = newNode(preorder[count]);
    for(i = start; i <= end; i++)
        if(inorder[i] == preorder[count])
            break;
    count++;
    node->left = pre_in_BST(inorder, preorder, start, i-1);
    node->right = pre_in_BST(inorder, preorder, i+1, end);
    return node;
}

main()
{
    int inorder[] = {2,3,5,8,10,12,15,17};
    int preorder[] = {10,5,2,3,8,15,12,17};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    Node* root = pre_in_BST(inorder, preorder, 0, size-1);
    cout << "BST - inorder Traversal:\n";
    inorderTrav(root);
    return 0;
}