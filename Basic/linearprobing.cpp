#include<iostream>
using namespace std;
class Hash{
int *a,s,counts;
public:
Hash(int n){
    a=new int[n];
    s=n;
 for(int i=0;i<s;i++)
        a[i]=-1;
 counts=0;}
void insert(int);
int delete1(int);
int search(int);
void display();
};
void Hash::insert(int x){
if(counts==s)
    cout<<"\nHash table Full";
else{
    int key=x%s;
    int t=key;
    if(a[key]==-1)
    {
      a[key]=x;
      counts++;
      cout<<"\n"<<"Element inserted at"<<key;
    }
    else{
        xyz:
            if(key==s-1)
                key=-1;
            key=key+1;
            if(key==t){
             return;
            }
            else{
                if(a[key]==-1)
                {
                    a[key]=x;
                    counts++;
                    cout<<"\n"<<x<<"Element Inserted at"<<key;
                    return;
                }
            }
            goto xyz;
    }
}
}
int Hash::delete1(int m){
int i;
int key=m%s;
if(counts==0)
    return 0;
if(a[key]==m){
    a[key]=-1;
    counts--;
    return key;
}
else{
    for(i=0;i<s;i++){
        if(a[i]==m)
        {
            a[i]=-1;
            counts--;
            return i;
        }
    }
    if(i==s){
        return 100;
    }
}
}
int Hash:: search(int m)
{
    int i;
    int key=m%s;
    if(counts==0)
    {
        return 0;
    }
    if(a[key]==m){
        return key;
    }
    else{
        for(i=0;i<s;i++){
            if(a[i]==m){
                return i;
            }
        }
        if(i==s)
            return 100;
    }
}
void Hash::display()
{
    for(int i=0;i<s;i++)
        if(a[i]!=-1)
        cout<<endl<<i<<" "<<a[i];
}
int main(){
     int n,x,y,z,ch,fg;
 cout<<"\n Enter size of hash table\n";
 cin>>n;
 Hash ob(n);
 while(1)
 {
  cout<<"\n1. insert\n2. Delete\n3. search\n4. display\n5. Exit\n enter ur choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:
    cout<<"\n Enter an Element to insert\n";
    cin>>x;
    ob.insert(x);
    break;
   case 2:
    cout<<"\n Enter an Element to Delete\n";
    cin>>y;
    fg=ob.delete1(y);
    if(fg==100)
    {

    cout<<"\nElement not in the List\n";
       }
    else if(fg==0)
    {
    cout<<"\n hash table Empty\n";
    }
    else
    {
     cout<<"\n deleted element "<<y<<" at position "<<fg<<endl;
    }
    break;
   case 3:
    cout<<"\n Enter an Element to Search\n";
    cin>>z;
    fg=ob.search(z);
    if(fg==100)
    {

    cout<<"\nElement not in the List\n";
       }
    else if(fg==0)
    {
    cout<<"\n hash table Empty\n";
    }
    else
    {
     cout<<"\n"<<z<<" element Searched at position "<<fg<<endl;
    }
    break;
   case 4:
    ob.display();
    break;
   case 5:
      return 0;
   default:
    cout<<"\n Wrong Choice\n";

  }
 }

 return 0;
}
