#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *previous;
    int info;
    struct node *next;
}nodetype ;

void insert(nodetype **, int, nodetype **);
void del(nodetype **, nodetype **);
void dele(nodetype **, nodetype **);
void display(nodetype *, nodetype *);
void specpos(nodetype **, nodetype **,int);
void alter(nodetype **, nodetype **);


int main()
{
    nodetype *start=NULL,*end=NULL;
    int n,ch,pos;
    char c;
    do
    {
        printf("enter\n1.insert\n2delete odd\n3.delete duplicate\n4.delete from specific pos.\n5.display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter no.:");
                    scanf("%d",&n);
                    insert(&start,n,&end);
                    break;
            case 2: if(start==NULL)
                       printf("empty");
                    else
                        del(&start, &end);
                    break;
            case 3: if(start==NULL)
                       printf("empty");
                    else
                        dele(&start, &end);
                    break;
            case 4: if(start==NULL)
                       printf("empty");
                    else
                        {
                            printf("enter the position:");
                            scanf("%d",&pos);
                            specpos(&start, &end,pos);
                        }
                    break;
            case 5: if(start==NULL)
                       printf("empty");
                    else
                        display(start, end);

                    break;
            case 6: alter(&start,&end);

        }

        printf("continue:");
        fflush(stdin);
        scanf("%c",&c);

    }while(c=='y' || c=='Y');

}

void insert(nodetype ** lt,int n, nodetype **rt)
{
    nodetype *p;
    p=(nodetype *)malloc(sizeof(nodetype));
    if(p==NULL)
        printf("kla");
    else
    {
        p->info=n;
        p->next=NULL;

        if(*rt==NULL)
        {
            *rt=p;
            *lt=p;
            p->previous=NULL;
        }
        else
        {
        (*rt)->next=p;
        p->previous=(*rt);
        (*rt)=p;
        }
    }
}
void del(nodetype **lt, nodetype **rt)
{
    nodetype *p=*lt, *q=*lt;

    while(q!=NULL)
    {
        if((q->info)%2!=0)
        {
            if(q==(*lt))
            {
                p=q;
                *lt=(*lt)->next;
                q=q->next;
                free(p);
            }
            else if(q==*rt)
            {
                p->next=NULL;
                *rt=p;
                free(q);
            }
            else
            {
                p->next=q->next;
                q->next->previous=p;
                free(q);
                q=p->next;

            }

        }
        else
        {
            p=q;
            q=q->next;
        }
    }
}

void display(nodetype *lt, nodetype *rt)
{
    while(lt!=NULL)
    {
        printf("%d ",lt->info);
        lt=lt->next;
    }
}

void dele(nodetype **lt, nodetype **rt)
{
    nodetype *p=*lt,*q,*r;
    while(p!=NULL)
    {
     r=(p)->next;
     q=p;

        while(r!=NULL)
        {
            if((p->info)==(r->info) )//&&(r==*rt) )
            {

               if(r==*rt)
               {q->next=NULL;
                *rt=q;
                free(r);
                r=q->next;}



            else //if((p->info)==(r->info))
            {
                q->next=r->next;
                r->next->previous=q;
                free(r);
                r=q->next;
            }
        }
            else
           {
            q=r;
            r=r->next;
           }
        }
        p=p->next;
    }

 /*  // nodetype *p=*lt,*q,*r;
    while(p!=NULL)
    {
     r=(p)->next;
     //q=p;

        while(r!=NULL)
        {

            if((p->info)==(r->info))// &&(r==*rt) )
            {
                            q=r;
                if(q==*rt)
                {
                  (q->previous)->next=NULL;
                  *rt=q;
                  free(q)  ;
                  r=NULL;
                }
                else
                {
                    (q->previous)->next=q->next;
                    (q->next)->previous=q->previous;
                    r=q->next;
                    free(q);
                }
                /*q->next=NULL;
                *rt=q;
                free(r);
                r=q->next;

            }
            }
            else if((p->info)==(r->info))
            {
                q->next=r->next;
                r->next->previous=q;
                free(r);
                r=q->next;
            }
    }
            else
           {
            //q=r;
            r=r->next;
           }
        }
        p=p->next;
    }*/

}

void specpos(nodetype **lt,nodetype **rt,int pos)
{
    nodetype *p=*lt,*q=*lt;
    int i=1;
    while(i!=pos)
    {
        p=q;
        q=q->next;
        i++;
    }
    if(q==*lt)
    {
        p=q;
        (*lt)=(*lt)->next;
        free(p);
    }
    else if(q==*rt)
    {
        p->next=NULL;
        *rt=p;
        free(q);
    }
    else
    {p->next=q->next;
    q->next->previous=p;
    free(q);}


}


void alter(nodetype **lt, nodetype **rt)
{
    nodetype *p, *q;
    p=(*lt);
    q=(*lt)->next;
    while(p!=NULL || q!=NULL)
    {
        if(q==(*rt))
        {
            p->next=NULL;
            *rt=p;
            free(q);
        }
        else
        {
            p->next=q->next;
            (q->next)->previous=p;
            free(q);
            //p=q;
            p=p->next;
            q=p->next;
        }
    }
}
