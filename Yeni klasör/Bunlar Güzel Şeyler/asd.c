#include <stdio.h>
#include <stdlib.h>
int main()
{
     char s[99];
     int i;
     system("cls");
     scanf("%s",s);
     i=strlen(s);
     s[i]='\n';
    int j,x;
    x=s[0];
    for(i=1;s[i]!='\n';i++)
    {
        j=s[i];
        j=j^x;
        printf("%c",j);
        //s[i]=j;
    }   
    getch();
}
