#include<stdio.h>
#include<windows.h>
struct ogrenci{
     int not1;
     int no;
     char isim[25];
     };
int ort_bul(struct ogrenci x[])
{
     return (x[0].not1 + x[1].not1 + x[2].not1)/3;
}
int main ()
{
     struct ogrenci x[3];
     int i,j;
     for(i=0;i<3;i++)
     scanf("%s%d%d",x[i].isim,&x[i].not1,&x[i].no);
     printf("%d\n", ort_bul(x));
     int max;
     int max_no;
     max_no=x[0].no;
     max=x[0].not1;
     for(i=1;i<3;i++)
          if(x[i].not1>max){ max=x[i].not1; max_no=x[i].no; }
          printf("%d\n",max);
          printf("%d\n",max_no);
          getch();
}
