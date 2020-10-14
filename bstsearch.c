#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    struct tree *left;
    int info;
    struct tree *right;

}treetype;

void insert(treetype**,int);
void search(treetype *,int,int *);
int fmax(treetype *);
void leftc(treetype*,int *);
int depth(treetype *);


int main()
{
    treetype *root=NULL,*m=NULL;
    int n,ch,k,l,f=0;
    char c;
    do
    {
        printf("enter\n1.insert\n2.search\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter element:");
                    scanf("%d",&n);
                    insert(&root, n);
                    break;
            case 2: if(root==NULL)
                       printf("empty");
                    else
                    {
                        printf("element to be searched:");
                        scanf("%d",&k);
                        search(root,k,&f);
                       if(f!=0)
                       {
                           printf("found");
                       }
                       else
                        printf("not found");

                    }
                    break;
            case 3: if(root==NULL)
                         printf("empty");
                    else
                    {
                       // l=fmax(root);
                        printf("%d",l);

                    }
                    break;
            case 4: if(root==NULL)
                         printf("empty");
                    else
                        leftc(root,&f);
                    printf("%d",f);
                    break;
            case 5: printf("%d", depth(root));


        }

        printf("continue:");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y' || ch=='Y');
}

void insert(treetype **rt, int n)
{
    treetype *p;
    if(*rt==NULL)
    {
        p=(treetype*)malloc(sizeof(treetype));
        if(p==NULL)
            printf("not enough");
        else
        {
            p->info=n;
            p->left=NULL;
            p->right=NULL;
        }
        *rt=p;
    }
    else
    {
        if((*rt)->info>n)
            insert(&((*rt)->left),n);
        else
            insert(&((*rt)->right),n);
    }
}
void search(treetype *rt, int k,int *f)
{
    if(rt==NULL)
        return ;
    else
    {
        if(rt->info==k)
        {
            (*f)=1;
            return ;
        }
    else
    {
       // if(rt->info>k)
        search(rt->left,k,f);
     //if(rt->info<k)
        search(rt->right,k,f);
        //return ;
    }
    }
}
int fmax(treetype *rt)
{
    int max,r;
    if(rt==NULL)
        return ;
    else
      {
          max=rt->info;
          r=fmax(rt->right);
          if(r>max)
            max=r;
          return max ;

      }


}*/

void leftc(treetype* rt,int *f)
{
    if(rt==NULL)
        return;
    else
    {
        leftc(rt->right,f);
        if(rt->left!=NULL)
            (*f)++;
        leftc(rt->left,f);
        return;


    }
}
int depth(treetype *rt)
{
    int dl,dr;
    if(rt==NULL)
        return 0;
    else
    {
        dl=depth(rt->left);
        dr=depth(rt->right);
        if(dl>dr)
            return (dl+1);
        else
            return (dr+1);
    }
}
//max. height
