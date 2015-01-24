#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<denemeler.h>
#define en 10
#define boy 10
int main ( )
{
    int i,j,d1=4,d2=4;
    char s[boy][en],a;
    for(i=0;i<boy;i++)
    {
                     for(j=0;j<en;j++)
                     {
                                      s[i][j]=' ';
                     }
    }
    while(1)
    {
    system("cls");
    
    s[d1][d2]='X';
    for(i=0;i<boy;i++)
    {                printf("\n-----------------------------------------\n|");
                     for(j=0;j<en;j++)
                     {
                                      printf(" %c |",s[i][j]);
                     }
    }
    printf("\n-----------------------------------------");
    a=getch();
    switch(a)
    {
             case 'w': s[d1][d2]=' '; d1--; break; 
             case 's': s[d1][d2]=' '; d1++; break; 
             case 'a': s[d1][d2]=' '; d2--; break; 
             case 'd': s[d1][d2]=' '; d2++; break; 
    }
    if(d1<0) d1=0;
    if(d2<0) d2=0;
    if(d2>(en-1)) d2=(en-1);
    if(d1>(boy-1)) d1=(boy-1);
    }
              
    system("pause");
}
