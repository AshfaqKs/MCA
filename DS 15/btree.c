// C program to to implement binary tree

#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node *root=NULL;

// Function to create a new node
Node* createNode( )
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    int item;
    printf("\nEnter element to insert : ");
    scanf("%d",&item);
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inserting a node in a binary tree
void insert( )
{
    Node* newNode = createNode( );
    if (root == NULL) {
        root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place
    // for insertion
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Insert new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        // if right child is not missing push it to the
        // queue
        else {
            queue[++rear] = temp->right;
        }
    }
}


// Function to search for a node in the binary tree
Node* search( )
{
    if (root == NULL) {
        return NULL;
    }
    int item;
    printf("\nEnter the element to search : ");
    scanf("%d",&item);
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == item) {
            return temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
    return NULL;
}

// function to perform inorder traversal in a binary tree
void inorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// function to perform inorder traversal in a binary tree
void preorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// function to perform inorder traversal in a binary tree
void postorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
   int ch;
   printf("\n\n1.Insert \n2.Search \n3.Preorder Traversal \n4.Inorder traversal \n5.Postorder Traversal \n6.Exit ");
   while(1)
   {
     printf("\n\nEnter Your Choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
         insert();
         break;
       case 2:
         search();
         break;
       case 3:
         preorder(root);
         break;
       case 4:
         inorder(root);
         break;
       case 5:
         postorder(root);
         break;
       case 6:
         exit(0);
         break;
       default:
       printf("\nEnter valid choice");
     }
   }
    return 0;
}
