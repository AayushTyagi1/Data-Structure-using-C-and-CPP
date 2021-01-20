#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
    char *c;
    int i;
    c=(char*)calloc(15,sizeof(char));
    gets(c);
    puts(c);
    free(c);
    int *a=(int*)malloc(5*sizeof(int));
    for(i=0;i<5;i++)
        scanf("%d",a+i);
    for(i=0;i<5;i++)
        printf("%d",*(a+i));
    a=realloc(a,10);
    for(i=0;i<10;i++)
        scanf("%d",a+i);
    for(i=0;i<10;i++)
        printf("%d",*(a+i));
}
