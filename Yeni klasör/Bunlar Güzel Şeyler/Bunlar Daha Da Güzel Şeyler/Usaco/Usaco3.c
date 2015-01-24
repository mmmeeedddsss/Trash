/*
PROG:friday
LANG:C
NAME:mmmeeed1
*/
#include<stdio.h>
#define MONTH 12
int IsLeapYear(unsigned long long int year)
{
     if(year%400==0)
     {
          if(year%100==0) return 0;
          return 1;    
     }
     if(year%4==0) return 1;
     return 0;
}

     int day = 0;
     int noOfDays[MONTH] = {31,28,31,30,31,30,31,31,30,31,30,31};
     int s[7];
     
int main()
{
     FILE *f1,*f2;
     f1=fopen("friday.in","r");
     f2=fopen("friday.out","w");
     unsigned long long int year,month;
     int i,x;
     fscanf(f1,"%d",&x);
     for(year=0;year<x;year++)
     {
          for(month=0;month<MONTH;month++)
          {
               day+=13;
               day%=7;
               s[day]++;
               day+=(noOfDays[month]-13);
               day%=7;
               if(month==1) if(IsLeapYear(year)) day++;
          }    
     }
     fprintf(f2,"%d",s[6]);
     for(i=0;i<6;i++) fprintf(f2," %d",s[i]);
     fprintf(f2,"\n");
     return 0;
}
