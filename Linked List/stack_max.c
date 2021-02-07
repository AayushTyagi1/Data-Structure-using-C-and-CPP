#include<stdio.h>
#include<stdlib.h>
typedef  struct node
{
    int info;
    struct node *next;
}node;

void insert(node **t,int n)
{
    node *p=(node *)malloc(sizeof(node));
    p->info=n;
    p->next=NULL;
    if(*t==NULL)*t=p;
    else {
        p->next=*t;
        *t=p;
    }
}
void del_max(node **t)
{
    int max=(*t)->info;
    node *p=*t,*temp=*t;
    while(temp!=NULL)
    {
        if(max<(temp->info))
            max=temp->info;
        temp=temp->next;
    }
    temp=*t;
    if(max==(*t)->info)
    {
        p=*t;
        *t=(*t)->next;
        free(p);
    }
    else{
        while(temp->next->info!=max)
        {
            temp=temp->next;
        }
        p=temp->next;
        temp->next=temp->next->next;
        free(p);
    }

}
void display(node *t)
{
    while(t!=NULL)
    {
        printf("%d",t->info);
        t=t->next;
    }
}
int main()
{
    node *T=NULL;
    int n;char ch;
    do
    {
        printf("Enter the element: ");
        scanf("%d",&n);
        insert(&T,n);
        printf("Do you want to continue..");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    del_max(&T);
    display(T);
}
