#include<iostream>
#include<algorithm>
using namespace std;
int partition(int a[],int start,int last)
{
    int pivot=a[start];
    int i=start,j=last;
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
            swap(a[i],a[j]);
    }if(i>j)
    swap(a[start],a[j]);
    return j;
}
void quicksort(int a[],int start,int last)
{
    int i;
    if(start<last){
        i=partition(a,start,last);
        quicksort(a,start,i-1);
        quicksort(a,i+1,last);
    }
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
quicksort(a,0,n);
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
