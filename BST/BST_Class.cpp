/*
Write a program for binary search tree (BST) having functions for the following operations:
 Insert an element (no duplicates are allowed),
 Delete an existing element,
 Traverse the BST (in-order, pre-order, and post-order),
 Maximum depth, and
 Minimum depth.

Made By: Gaurav Baweja
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

class BST 
{
    Node *root = NULL;
    void inorderTrav(Node *node)
    {
        if(node->left)
            inorderTrav(node->left);
        cout << node->data << ' ';
        if(node->right)
            inorderTrav(node->right);
    }
    void preorderTrav(Node *node)
    {
        cout << node->data << ' ';
        if(node->left)
            preorderTrav(node->left);
        if(node->right)
            preorderTrav(node->right);
    }
    void postorderTrav(Node *node)
    {
        if(node->left)
            postorderTrav(node->left);
        if(node->right)
            postorderTrav(node->right);
        cout << node->data << ' ';
    }
    Node* inorderSuccessor(Node* node)
    {
        while(node->left)
            node = node->left;
        return node;
    }
    Node* deleteNode(int val, Node* node)
    {
        if(node == NULL)
            return node;
        if(val < node->data)
            node->left = deleteNode(val, node->left);
        else if(val > node->data)
            node->right = deleteNode(val, node->right);
        else
        {
            if(node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = inorderSuccessor(node->right);
            node->data = temp->data;
            node->right = deleteNode(temp->data, node->right);
        }
        return node;
    }
    int maxDepthTree(Node* node)
    {
        if (node == NULL)
            return -1;
        return max(maxDepthTree(node->left), maxDepthTree(node->right)) + 1;
    }
    int minDepthTree(Node* node)
    {
        if (node == NULL)
            return -1;
        return min(maxDepthTree(node->left), maxDepthTree(node->right)) + 1;
    }
    public:
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
        void deleteVal(int val)
        {
            if(root)
                root = deleteNode(val, root);
            else
                cout << "Tree is empty\n";
        }
        
        void travInorder()
        {
            if(root)
            {
                inorderTrav(root);
                cout << endl;
            }
            else 
                cout << "Empty tree\n";
        }
        
        void travPreorder()
        {
            if(root)
            {
                preorderTrav(root);
                cout << endl;
            }
            else 
                cout << "Empty tree\n";
        }
        
        void travPostorder()
        {
            if(root)
            {
                postorderTrav(root);
                cout << endl;
            }
            else 
                cout << "Empty tree\n";
        }
        int maxDepth()
        {
            return maxDepthTree(root); 
        }
        int minDepth()
        {
            return minDepthTree(root);
        }
};

main()
{
    int arr[] = {5,2,10,19,6,1,11,15,3,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    BST bsTree;
    for(int i = 0; i < size; i++)
        bsTree.insert(arr[i]);
    bsTree.travInorder();
    bsTree.travPreorder();
    bsTree.travPostorder();
    cout << "Max Depth of Tree is " << bsTree.maxDepth() << endl;
    cout << "Min Depth of Tree is " << bsTree.minDepth() << endl;
    bsTree.deleteVal(15);
    bsTree.deleteVal(19);
    bsTree.deleteVal(5);
    bsTree.travInorder();
    return 0;
}