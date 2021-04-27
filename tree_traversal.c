#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *left , *right;
}node;
// to create new node
node *create_node(int val)
{
   node *new_node =(node *)malloc(sizeof(node));
   new_node -> key = val;
   new_node -> right = NULL;
   new_node -> left = NULL;
   return new_node;
}
node* insert_left(node *root , int data)
{
  root ->left = create_node(data);
  return root ->left;
}
//here was the bug😒 costed more than an hour.
node* insert_right(node *root , int data)
{
  root ->right = create_node(data);
  return root ->right;
}
void inorder(node *root)
{
    if(root == NULL) return;
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);

}

void preorder(node *root)
{
    if(root == NULL) return;
         printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);

}
void postorder(node *root)
{
  if(root == NULL) return;
    
        preorder(root->left);
        preorder(root->right);
        printf("%d ", root->key);
}
int main()
{
    node *root = create_node(3);
    insert_left(root ,4);
    insert_right(root , 5);
    insert_left(root->left , 12);
    insert_right(root->right , 13);
    insert_left(root->left->left , 123);

    
    printf("Inordr Traversal:");
    inorder(root);
    printf("\n Preorder Traversal:");
    preorder(root);
    printf("\n Postorder Traversal");
    postorder(root);

    printf("\n");

    return 0;
}

