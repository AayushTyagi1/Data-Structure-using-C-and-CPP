/*WAP to store n elements in an array &then find and print
1.Third repeating element
2.third non repeating element
*/
#include<stdio.h>
void main()
{
    int a[30],n,i,r=0,j,k,c,nr=0,f;
    printf("Enter the limit of array :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=i+1;j<n;j++)
        {
            f=0;
            if(a[i]==a[j])
            {
                r++;c=1;
                for(k=i-1;k>=0;k--)
                {

                    if(a[i]==a[k])
                     {
                           f=1;
                           break;
                     }
                }
                if(f==1)r--;
                break;
            }
        }
        if(c==0&&i!=j)
                nr++;
        if(r==3)
            {printf("repeating = %d\n",a[i]);r++;}
        if(nr==3)
            {printf("non repeating = %d\n",a[i]);nr++;}
    }

}
