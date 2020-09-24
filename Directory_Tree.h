#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BINARY TREE NODE DECLARAION

typedef struct bintreenode
{
    int data;
    struct bintreenode *left;
    struct bintreenode *right;
}BinaryTreeNode;

//SINGLY LINKED LIST NODE DECLARATION

typedef struct llnode
{
    BinaryTreeNode *btnode;
    struct llnode *next; 
}LLnode;

//QUEUE STRUCTURE DECLARATION

typedef struct queue{
    LLnode *front;
    LLnode *rear;
}Q;

//SOME QUEUE UTILITY FUNCTIONS

int isEmptyQueue (Q *queue)
{
    return (queue->front == NULL);
}

Q *CreateQ ()
{
    Q *queue;
    queue = (Q*)malloc(sizeof(Q));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue (Q *queue, BinaryTreeNode *node)
{
    

    LLnode *newNode;
    newNode = (LLnode*)malloc(sizeof(LLnode));
    newNode->btnode = node;
    newNode->next = NULL;
    if (queue->rear)
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL)
    {
        queue->front = queue->rear;
    }
}

BinaryTreeNode *dequeue (Q *queue)
{
    BinaryTreeNode *data;
    LLnode *temp;
    if (isEmptyQueue(queue))
    {
        printf ("Empty Queue!\n");
        return NULL;
    }
    else
    {
        temp = queue->front;
        data = temp->btnode;
        queue->front = queue->front->next;
        free (temp);
        return data;
    }
}

void deleteQueue (Q *queue)
{
    LLnode *temp;
    while (queue->front)
    {
        temp = queue->front;
        queue->front = queue->front->next;
        free (temp);
    }
    free (queue);
}

//FUNCTION TO CREATE A NEW NODE IN A TREE BY GIVING ITS DATA

BinaryTreeNode* newNode(int data) 
{ 
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 

//RECURSIVE PREORDER TRAVERSAL

void preorder (BinaryTreeNode *root)
{
    if(root)
    {
        printf ("%d\t", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

//RECURSIVE INORDER  TRAVERSAL

void inorder (BinaryTreeNode *root)
{
    if (root)
    {
        inorder (root->left);
        printf ("%d\t", root->data);
        inorder (root->right);
    }
}

//RECURSIVE POSTORDER TRAVERSAL

void postorder (BinaryTreeNode *root)
{
    if (root)
    {
        postorder (root->left);
        postorder (root->right);
        printf ("%d\t", root->data);
    }
}

//LEVEL ORDER TRAVERSAL

void levelorder (BinaryTreeNode *root)
{
    BinaryTreeNode *temp;
    Q *queue = CreateQ();
    if (!root)
    {
        return;
    }
    enqueue (queue, root);
    while (!(isEmptyQueue(queue)))
    {
        temp = dequeue (queue);
        printf ("%d\t", temp->data);
        if (temp->left)
        {
            enqueue (queue, temp->left);
        }
        if (temp->right)
        {
            enqueue (queue, temp->right);
        }
    }
    deleteQueue(queue);
}

//                                              ***BINARY SEARCH TREES***

//BINARY SEARCH FUNCTION

//      RECURSIVE

BinaryTreeNode *search (BinaryTreeNode *root, int data)
{
    if (!root)
    {
        return NULL;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
    return root;
}

//         NON-RECURSIVE

BinaryTreeNode *searchNR (BinaryTreeNode *root, int data)
{
    if (!root)
    {
        return NULL;
    }
    while (!root)
    {
        if (data == root->data)
        {
            return root;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
        return NULL;
    }
}

//FUNCTION TO FIND MINIMUM ELEMENT IN BINARY SEARCH TREE

BinaryTreeNode *findMin (BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL)   //base case
    {
        return root;
    }
    else
    {
        return findMin (root->left);
    }
}

//FUNCTION TO FIND MAXIMUM ELEMENT IN BINARY SEARCH TREE

BinaryTreeNode *findMax (BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->right == NULL)   //base case
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
}

//FUNCTION TO INSERT IN BINARY SEARCH TREE

BinaryTreeNode *insertBST (BinaryTreeNode *root, int data)
{
    if (!root)          //base case
    {
        root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        root->data = data;
        root->left = root->right = NULL;
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertBST (root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insertBST (root->right, data);
        }
    }
    return root;
}

//FUNCTION TO DELETE IN BINARY SEARCH TREE

BinaryTreeNode* deleteBST(BinaryTreeNode* root, int data) 
{ 
    if (root == NULL)
        return root; 
    if (data < root->data) 
        root->left = deleteBST(root->left, data); 
    else if (data > root->data) 
        root->right = deleteBST(root->right, data); 
    else
    {  
        if (root->left == NULL) 
        { 
            BinaryTreeNode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            BinaryTreeNode *temp = root->left; 
            free(root); 
            return temp; 
        } 
        BinaryTreeNode* temp = findMax(root->left); 
        root->data = temp->data; 
        root->left = deleteBST(root->left, temp->data); 
    } 
    return root; 
} 
  


