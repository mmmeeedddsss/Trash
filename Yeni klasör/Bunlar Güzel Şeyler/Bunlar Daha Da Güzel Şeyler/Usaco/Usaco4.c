/*
PROG:beads
LANG:C
NAME:mmmeeed1
*/
#include<stdio.h>

char neckl[350];

int say(int start,char dir,int lenght,char currcolor)
{
     int count = 0;
     int addition = dir == 'r' ? 1 : -1;
     int i = start;
     int cchng = 1;
     while( i < lenght )
     {
          if( currcolor == 'w' && neckl[i] != 'w' )
               currcolor = neckl[i];
          if( currcolor != neckl[i] && currcolor != 'w' && neckl[i] != 'w' && cchng != 0 )
          {
               currcolor = neckl[i];
               cchng--;
          }
          if( neckl[i] == currcolor || neckl[i] == 'w' )
          {
               count++;
               i += addition;
          }
          else
               return count;
          if( i == lenght)
               i = 0;
          if( i < 0 )
               i = lenght - 1;
          if( i == start )
               return count;
     }
}

int main()
{
     FILE *f1 = fopen("beads.in","r");
     FILE *f2 = fopen("beads.out","w");
     int max = 0,lenght;
     fscanf(f1,"%d",&lenght);
     fscanf(f1,"%s",neckl);
     int i;
     char lastcolor = 'i';
     
     for( i=0;i<lenght;i++ )
     {
          if( lastcolor != neckl[i] )
          {
               lastcolor = neckl[i];
               
               if( say( i , 'r' , lenght , lastcolor) > max )
                    max = say( i , 'r' , lenght , lastcolor );
               if( say( i , 'l' , lenght , lastcolor ) > max )
                    max = say( i , 'l' , lenght , lastcolor );
          }
     }
     
     /* 
     for( i=0;i<lenght;i++ )
     {
          if( brokeat(i,lenght) > max)
               max = brokeat(i,lenght);
     }
     */
     fprintf(f2,"%d\n",max);
     return 0;
     
}
