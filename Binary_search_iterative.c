// Aayush Tyagi
// Section: A
// 2013206
#include <stdio.h>
#define max 100
int main()
{
    int T, arr[max],n,i,key,count;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        count=0;
        for(i=0;i<n;i++)// Input Array
            scanf("%d",&arr[i]);
        scanf("%d",&key); //Input the key
        //Binary Search
        int mid,left=0,right=n-1,flag=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            count++;
            if(arr[mid]==key)
            {
                flag=1;
                break;
            }
            else if(arr[mid]<key)
                left=mid+1;
            else
                right=mid-1;
        }

        if(flag==0)
        {
            printf("NOT PRESENT\n");
        }
        else{
            printf("PRESENT\n");
        }
        printf("Number of comparisons: %d\n",count);
    }
}

