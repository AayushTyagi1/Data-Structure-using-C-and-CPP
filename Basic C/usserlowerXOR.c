#include<stdio.h>

char* upper(char *a)
{
    int x=32;
    for(int i=0; a[i]!='\0'; i++)
        a[i] = a[i] & ~x;
    return a;
}
int main()
{
    char a='A';
    a = a | 32;
    printf("%c",a);
    char x[]="aayush";
    printf("%s",upper(x));
}



