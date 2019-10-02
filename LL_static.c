//Create a link list of 3 nodes and print them
#include<stdio.h>
typedef struct node
{
    int info;
    struct node*next;
} link;
int main()
{
    link *A,*temp;
    A=NULL;
    link a,b,c;
    scanf("%d%d%d",&a.info,&b.info,&c.info);
    A=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    temp=A;
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }

}
/*#include<stdio.h>
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
    printf("Enter the number of user: ");
    scanf("%d",&n);
    A = (link*)malloc(sizeof(link));
    scanf("%d",&(A->info));
    A->next = NULL;
    temp = A;
    for(i=1; i<n; i++)
    {
        //if(i==n-1){temp->next=NULL;}
        if(i==n-1)
            temp->next = NULL;
        else
        {
            temp->next=(link*)malloc(sizeof(link));
            if(n==1)
                A->next = temp->next;
        }
        scanf("%d",&(temp->info));
        temp=temp->next;
    }
    temp = A;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}*/
