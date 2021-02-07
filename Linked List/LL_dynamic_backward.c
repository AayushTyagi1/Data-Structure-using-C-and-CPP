#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} link;

int main()
{
    int n,i;
    link *A,*temp;
    A=NULL;
    printf("Enter the number of user: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            temp=(link*)malloc(sizeof(link));
            scanf("%d",&(temp->info));
            A=temp;
            A->next=NULL;
        }
        else
        {
            temp=(link *)malloc(sizeof(link));
            temp->next=A;
            scanf("%d",&(temp->info));
            A=temp;
        }
    }
    temp=A;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}
