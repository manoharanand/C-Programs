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
   node *new_node = malloc(sizeof(node));
   new_node -> key = val;
   new_node -> right = NULL;
   new_node -> left = NULL;
   return new_node;
}
node* insert_val(node *root , int val)
{
   if(root == NULL) return create_node(val);

   if(val < root->key)
      root ->left = insert_val(root->left , val);
   else
      root->right = insert_val(root->right , val);
}
node *min_value_node(node *ptr) {
  node *current = ptr;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

node* delete_val(node* root , int val)
{
  if (root == NULL)
    return root;
  else if(val < root ->key)
    root->left = delete_val(root->left , val);
  else if(val > root->key)
    root->right = delete_val(root->right , val);
  else
  {
    if(root->left = NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right = NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
    else
    {
      // If the node has two children
    node *temp = min_value_node(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = delete_val(root->right, temp->key);
    
    }

  }
}
void inorder(node *root)
{
    if(root == NULL) return;
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);

}
int main()
{
  node *root = NULL;
  root = insert_val(root, 8);
  root = insert_val(root, 3);
  root = insert_val(root, 1);
  root = insert_val(root, 6);
  root = insert_val(root, 7);
  root = insert_val(root, 10);
  root = insert_val(root, 14);
  root = insert_val(root, 4);


  printf("Inorder traversal: ");
  inorder(root);

  printf("\nAfter deleting 10\n");
  root = delete_val(root, 10);
  printf("Inorder traversal: ");
  inorder(root);

    return 0;
}

