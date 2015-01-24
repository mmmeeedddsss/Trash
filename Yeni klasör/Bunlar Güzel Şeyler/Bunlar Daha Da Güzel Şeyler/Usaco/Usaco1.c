/*
PROG:ride
LANG:C
NAME:mmmeeed1
*/
#include<stdio.h>
#include<stdlib.h>
//char alphabeth[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
     FILE *f1,*f2;
     f1=fopen("ride.in","r");
     f2=fopen("ride.out","w");
     char s[7],u[7];
     int i;
     fscanf(f1,"%s",s);
     fscanf(f1,"%s",u);
     //printf("%s  %s",s,u);
     unsigned long long int x=1,y=1;
     for(i=0;i<strlen(s);i++)
     {
          x*=(s[i]-64);
          //printf("X --> %d\n",x);
          if(y%47!=0) x=x%47;
     }
     for(i=0;i<strlen(u);i++)
     {
          y*=(u[i]-64);
          //printf("Y --> %d\n",y);
          if(y%47!=0) y=y%47;
     }
     //printf("%llu  %llu",x,y);
     if(x%47==y%47) fprintf(f2,"GO\n");
     else fprintf(f2,"STAY\n");
     return 0;
}
