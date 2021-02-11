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

void multiply(node *n1, node *n2)
{

}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->info<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node *n1=NULL, *n2=NULL;
    insert(&n1,4);
    insert(&n1,7);
    insert(&n1,8);
    insert(&n1,9);
    insert(&n1,8);
    insert(&n1,1);
    display(n1);
    insert(&n2,3);
    insert(&n2,6);
    insert(&n2,1);
    insert(&n2,3);
    insert(&n2,2);
    insert(&n2,2);
    display(n2);

    node *ans=multiply(n1,n2);
}
