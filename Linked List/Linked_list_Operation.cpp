#include<iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node *next;
} node;

void insert(node **head, int n)
{
    node *p=(node *)malloc(sizeof(node));
    if(p)
    {
        p->info=n;
        p->next=NULL;
        if(*head == NULL)
        {
            *head=p;
        }
        else
        {
            p->next= *head;
            *head=p;

        }
    }
    else
    {
        cout<<"MEMORY ERROR!";
    }
}

int main()
{
    node *head=NULL;
    while(1)
    {
        int n;
        cin>>n;
        insert(&head, n);
    }
}
