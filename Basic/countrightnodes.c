#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree * left;
    int info;
    struct tree * right;

}treetype;

void insert(treetype **,int);
void count(treetype *,int *);

int main()
{
    treetype *root=NULL;
    int num,c=0;
    char ch;
    do
    {
        printf("enter the element");
        scanf("%d",&num);
        insert(&root,num);

        printf("do you wish to continue");
        fflush(stdin);
        scanf("%c",&ch);


    }while(ch=='y' || ch== 'Y');
    count(root,&c);
    printf("count  : %d",c);

}

void insert(treetype ** rt, int n)
{
    treetype *p;
    if((*rt)==NULL)
    {
        p=(treetype *)malloc(sizeof(treetype));
        if(p==NULL)
            printf("not en. space");
        else
        {
         p->info=n;
         p->left=NULL;
         p->right=NULL;
         *rt=p;
        }

    }
    else
    {
        if(n>(*rt)->info)
            insert(&(*rt)->right,n);
        else if(n<(*rt)->info)
            insert(&(*rt)->left,n);

    }
}
void count(treetype * rt, int *c)
 {
    if(rt==NULL)
        return;
    else
        count(rt->left, c);
        if(rt->right !=NULL)
            (*c)=(*c)+1;
        count(rt->right,c);
        return;

 }
