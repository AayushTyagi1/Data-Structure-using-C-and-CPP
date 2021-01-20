#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *f=NULL,*fp=NULL;
    char ch;
    if(argc!=2)
        printf("\nInvalid argument");
    else
    f=fopen(argv[1],"r");
    fp=fopen("copy2.c","w");
    while(1)
    {
        ch=fgetc(f);

        if(ch==EOF)
            break;
        fputc(ch,fp);
    }
    fclose(f);
    fclose(fp);
}
