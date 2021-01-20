#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
         int data;
         struct node *next;
}node;
void push(node **top)
{
         node *temp;
         temp=(node *)malloc(sizeof(node));
         printf("\nEnter a value: ");
         scanf("%d",&(temp->data));
         temp->next=*top;
          *top=temp;
           //printf("%d %d %d %d\n",temp->data,temp->next,(*top)->data,(*top)->next);
          //free(temp);
}
node * pop(node *top){
         struct node *p;
         printf("\nThe popped element is %d",top->data);
         top=top->next;
         return top;
}
void  display(node *top)
{
         node *temp;
         temp=top;
         while(temp!=NULL)
         {
                  printf("%d ",temp->data);
                  temp=temp->next;
         }
         free(temp);
}

void main()
{
         struct node *top=NULL;
         int choice;
         do
         {
         printf("\n\n\t\t**Linked List**\n");
         printf("\n1.Insert Element\n2.Pop Element\n3.Display\n4.exit");
         printf("\nEnter your Choice :");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
                  push(&top);
                  break;
         case 2:
                  if(top==NULL)
                           printf("\n\tStack is Empty\n");
                  else
                           top=pop(&top);
                   break;
         case 3:
                  if(top==NULL)
                           printf("\n\tStack is Empty\n");
                  else
                           display(top);
                    break;
         case 4:
                  exit(0);
         default:
                  printf("\n\tInvalid Choice.\n");
         }
         }
         while(1);
}
