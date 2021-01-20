// Aayush Tyagi
// Section: A
// 2013206
#include <stdio.h>
#define max 100

int BinarySearch(int arr[], int key, int l, int r,int count)
{
    if(l>r)
        return -count;
    int mid = l + (r-l)/2;
    if(arr[mid]==key)
        return count+1;
    if(arr[mid]<key)
        return BinarySearch(arr,key,mid+1,r,count+1);
    return BinarySearch(arr,key,l,mid-1,count+1);
}
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
        int mid,left=0,right=n-1;
        count=0;
        count = BinarySearch(arr,key,left,right,count);

        if(count<0)
        {
            printf("NOT PRESENT\n");
            printf("Number of comparisons: %d\n",-count);
        }
        else{
            printf("PRESENT\n");
            printf("Number of comparisons: %d\n",count);
        }

    }
}

