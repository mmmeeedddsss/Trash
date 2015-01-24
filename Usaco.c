#include<stdio.h>
int fonk(char **s,int x,int y)
{
     int i,j;
     printf("%d %d",x,y);
     for(i=0;i<x;i++)
          for(j=0;j<y;j++)
               printf("%c",s[i][j]);
     int acaba;
     int max=0;
     for(i=0;i<x;i++)
          for(j=0;j<y;j++)
               if(s[i][j]=='*')
               {
                    acaba=aha_buldum(s,i,j);
                    if(acaba>max)
                         max=acaba;
               }
     return max;
}
int aha_buldum(char **s,int i,int j)
{
     int sayac=0;
     s[i][j]='.';
     if(s[i][j-1]=='*') { sayac++; sayac+=aha_buldum(s,i,j-1); }
     if(s[i-1][j]=='*') { sayac++; sayac+=aha_buldum(s,i-1,j); }
     if(s[i][j+1]=='*') { sayac++; sayac+=aha_buldum(s,i,j+1); }
     if(s[i+1][j]=='*') { sayac++; sayac+=aha_buldum(s,i+1,j); }
     return sayac;
}
int main()
{
     int i,j,x,y;
     system("cls");
     scanf("%d%d",&x,&y);
     char s[x][y],temp;
     scanf("%c",&temp);
     for(i=0;i<x;i++)
     {
          for(j=0;j<y;j++)
          {
               scanf("%c",&s[i][j]);
          }
          scanf("%c",&temp);
     }

     printf("\n%d\n\n",fonk(s,x,y));
     getch();
}
