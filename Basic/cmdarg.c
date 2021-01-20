#include<stdio.h>
int main(int argc,char **argv)
{
    int i;
    for(i=0;i<argc;i++)
    {
        printf("This is argument %d and value is %s\n\n",argc,argv[i]);
    }
     for(i=0;i<argc;i++)
    {
        printf("value is %s\n",*argv);argv+=1;
    }
}
