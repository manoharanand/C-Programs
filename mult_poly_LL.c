#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff, exp;
    struct node *next;
}node;
// to create new node
/*
node *create_node(int x, int y)
{
   node *new_node = malloc(sizeof(node));
   new_node -> coeff = x;
   new_node -> exp = y;
   new_node -> next = NULL;
   return new_node;
}*/
node *insert_node(node *head , int coefficient , int exponent)
{
    node *new_node = malloc(sizeof(node));
    new_node->coeff = coefficient;
    new_node->exp = exponent;
    new_node->next =NULL;
    if(head == NULL)
      head = new_node;
    else
    {
        while (head->next !=NULL)
        {
            head = head->next;
        }
        head = new_node;
    }
    return head;
}

void remove_duplicate(node *head  )
{
   node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL) {
 
            // If powerer of two elements are same
            if (ptr1->exp == ptr2->next->exp) {
 
                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
 
                // remove the 2nd element
                free (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void print_list( node* head)
{
    while (head->next != NULL) {
        printf("%dx^%d +",head->coeff ,head->exp); 
        if( head->next!=NULL && head->next->coeff >=0)
          printf("+");
        head = head->next;
    }
    printf("%dx^%d +",head->coeff ,head->exp);
}
node* multiply_ll(node *h1 , node *h2 , node *h3)
{
  node *ptr1 , *ptr2 ;
  ptr1 = h1, ptr2 = h2 ;
  while(ptr1 != NULL)
  {
      while (ptr2 !=NULL)
      {
          int coefficient = (ptr1->coeff) * (ptr2->coeff);
          int exponent = (ptr1 ->exp) * (ptr2->exp);
          h3 = insert_node(h3 , coefficient, exponent);
          ptr2= ptr2->next;
      }
      ptr2 = h2;
      
      ptr1 = ptr1->next;
      
  }
  return h3;

}

int main()
{
    node *poly1 , *poly2 , *poly3;
    poly1 = insert_node(poly1, 3, 3);
    poly1 = insert_node(poly1, 6, 1);
    poly1 = insert_node(poly1, -9, 0);
 
    // Creation of 2nd polynomial: 6x^1 + 8
    poly2 = insert_node(poly2, 9, 3);
    poly2 = insert_node(poly2, -8, 2);
    poly2 = insert_node(poly2, 7, 1);
    poly2 = insert_node(poly2, 2, 0);

   // multiply_ll(poly1 , poly2 , poly3);
    print_list(poly1);
    printf("\n");
   // print_list(poly2);
    printf("\n");
   // print_list(poly3);
    printf("\n");
  

    return 0;
}

