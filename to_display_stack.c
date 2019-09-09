/*Problem Statement: Write a menu driven program where user
 can press:
 1.to push element into stack
 2.to pop element from stack
 3.to display elements of stack
 Give choice to user if he wishes to exit.
 Name: Aayush Tyagi
 Section: A
 Roll no: 03
*/
#define max 50//limit of stack
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int PUSH(int s[],int t,int v)//Function to insert an
//element at the top of stack
{
    s[t]=v;
}
int POP(int s[],int t)//function to pop
//top element of stack
{
    printf("The popped value is %d\n",s[t]);
}
void Display(int s[],int t)//function to display
//element of stack
{
    for(;t>=0;t--)
        printf("%d\n",s[t]);
}
void main()
{
    int stack[max],top=-1,value;
    int ch;char choice;
    do
    {
        printf("Enter :\n 1. To push \n 2. To pop \n");
        printf(" 3. To display \n");//Menu
        printf("Enter choice: ");
        scanf("%d",&ch);
        fflush(stdin);
        if(ch==1)
        {
            if(top==max-1)//Extreme Condition check
                printf("Stack Overflow\n");
            else
            {
                printf("Enter value to be pushed: ");
                scanf("%d",&value);
                PUSH(stack,++top,value);//function call
            }
        }
        else if(ch==2)
        {
            if(top==-1)//Extreme Condition check
                printf("Stack is empty\n");
            else
                POP(stack,top--);//function call
        }
        else if(ch==3)
        {
            if(top==-1)//Extreme Condition check
                printf("Stack is empty\n");
            else
                Display(stack,top);//function call
        }
        printf("Do you want to continue Y/N?\n");
        fflush(stdin);
        scanf("%c",&choice);

    }while(toupper(choice)=='Y');
    getch();
}
