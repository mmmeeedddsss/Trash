/*
PROG:palsquare
LANG:C
NAME:mmmeeed1
*/
#include<stdio.h>
#include<stdlib.h>

char* getInBaseN( char* inBase , int num , int n )
{
     int i = 0;
     while( num > 0 )
     {
          inBase[i++] = (char)('0' + (num % n));
          num /= n;
     }
     inBase[i] = '\0';
     return inBase;
}

char* rotate( char* input, int len )
{
     int i,j;
     for( i=0, j= len-1; i<j; i++,j-- )
     {
          int temp = input[i];
          input[i] = input[j];
          input[j] = temp;    
     }
     return (char*)input;
}

int ispal( char* input,int len )
{
     int i,j;
     for( i=0, j= len-1; i<j; i++,j-- )
     {
          if( input[i] != input[j] )
               return 0;
     }
     return 1;
}

int main()
{
     FILE *fi = fopen("palsquare.in","r");
     FILE *fo = fopen("palsquare.out","w");
     char a[10];
     char b[10];
     int n,i;
     fscanf(fi,"%d",&n);
     for( i=1; i<300; i++ )
     {
               char *inbase = getInBaseN( b,i*i,n );
               int len = strlen( inbase );
               if( ispal( inbase, len ) )
               {
                    char *iInBaseN = getInBaseN( a,i,n );
                    fprintf(fo,"%s %s\n",iInBaseN,inbase);
               }
     }
     fclose(fo);
     return 0;
}
