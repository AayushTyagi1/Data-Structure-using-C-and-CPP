#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *p;
    p=(char*)malloc(15*sizeof(char));
    gets(p);
    puts(p);
}
