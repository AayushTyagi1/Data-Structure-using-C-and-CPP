#include<iostream>
using namespace std;
int median(int s[],int  n,int d){
    if(n==1)
        return s[0];
        int l[n-1],r[n-1],e[n-1];
        int k=0,j=0,h=0;
    for(int i=0;i<n;i++){
        if(s[i]<s[0]){
            l[k++]=s[i];}
        else if(s[i]>s[0]){
                r[j++]=s[i];}
        else
            e[h++]=s[i];
        }
    if(k>=d)return median(l,k,d);
    else if(k+h>=d){return e[0];}
    else
        return(median(r,j,d-(k+h)));
}
int main(){
int a[]={8,36,1,45,10,57,98,21,30};
int n=sizeof(a)/sizeof(a[0]);
int m=median(a,n,5);
cout<<5<<"th smallest element is : "<<m;
}
