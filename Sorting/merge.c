#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100
void ins_arr(int p[max],int l)                         //insert array function definition

{
    int i;
    printf("enter elements in an array\n");
    for(i=0;i<l;i++)
    {
        scanf("%d",&p[i]);
    }
}

void merge(int ar[],int i1,int j1,int i2,int j2)
{
int temp[max],i=i1,j=j2,k=0;
while((i<=j1)&&(i2<=j2))
{
if(ar[i]<ar[j])
     temp[k++]-ar[i++];
else
     temp[k++]-ar[j++];
}
while (i<=j1)
{
temp[k++]=ar[i++];
}
while(j<=j2)
{
temp[k++]=ar[j++];
}
for(i=i1,j=0;i<=j2;i++,j++)
{
ar[i]=temp[j];
}
}
void m_sort(int a[max],int lb, int ub)
{
int mid=0;
if(lb<ub)
{
mid=(lb+ub)/2;
m_sort(a,lb,mid);
m_sort(a,(mid+1),ub);
merge(a,lb,mid,(mid+1),ub);
}
}
void disp(int a[],int n)                                   //display function function
      {
         int i;
         for(i=0;i<n;i++)
         {
             printf("%d ",a[i]);
         }
         // printf("\n");
      }
        void main ()                                          // Main function
        {
          int c,n,ar[max];
          char ch;
          do
          {
              printf("enter your choice\npress 1 to insert clement\nPress2 to sort\npress 3 to display\n");
              scanf("%d",&c);
              switch(c)
              {
              case 1:
               printf("enter the limit of the array\n");
               scanf("%d",&n);
               ins_arr(ar,n);                                                    //insert array function call
               break;

              case 2:
                 m_sort(ar,0,(n-1));                                            // merge sort function call
                 break;
              case 3:
                 disp(ar,n);                                                   //display functional call
                 break;
                }
                printf("Do you want to continue y/n \n");
                fflush (stdin);
                scanf("%c",&ch);
                }while(ch=='Y'||ch=='y');
        }

