#include<stdio.h>
#include<ctype.h>
#define maxsize 50
char postfix[] = "235*+6+";
    int stack[maxsize];
    int top = -1;
 

void push_stack(int data)
{
    if(top >= maxsize)
      printf("Stack Overflow");
    else
    {
        stack[top] = data;
        top+=1;
    }
      
}
int pop_stack()
{
    int x;
    if(top < 0 )
    printf("Stack underflow");
    else
    {
        top-=1;
        x = stack[top];
    }
    return x;
}
void evaluate_postfix(char postfix[] , int n)
{
    int A, B , val = 0 , i ;
    char ch;
     for (i = 0; i<n; i++)
      {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push_stack(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
         {
            
            A = pop_stack();
            B = pop_stack();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            push_stack(val);
        }
    }

}
int main()
{
    
    int n = sizeof(postfix) / sizeof(postfix[0]);
    evaluate_postfix(postfix , n);
    printf("Upon evalution the value is %d" , &stack[top]);

    return 0;
}