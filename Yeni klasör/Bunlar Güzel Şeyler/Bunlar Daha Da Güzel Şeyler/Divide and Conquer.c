#include<stdio.h>
int * Conquer(int *a,int *b,int *c,int n)
{
         int i=0,j=0,k=0;
         int c_n=n/2,b_n=n/2;
         while(i<c_n&&i<b_n)
               if(b[b_n]>c[c_n]) a[i++]=b[b_n++];
               else a[i++]=b[b_n++];
         if(i==c_n) while(i<n) a[i++]=b[b_n++];
         else while(i<n) a[i++]=c[c_n++];
         printf("Conquer-->\n");
         for(i=0;i<n;i++) printf("%d",a[i]);
         getch();
         system("cls");
         return a;
}

void Divide(int *s,int b_n,int c_n)
{
     int b[b_n],c[c_n];
     
     //if(b_n>0)
     //{
          //printf("adsad");
          int i,j;
          if(b_n>0) for(i=0;i<n/2;i++) b[i]=s[i];
          if(c_n>0)for(j=0;j<n/2;j++) c[j]=s[i++];
          for(i=0;i<n;i++) printf("%d\n",s[i]);
          getch();
          if(b_n>0) Divide(b,b_n/2);
          if(c_n>0) Divide(c,c_n/2);
     //}
     s=Conquer(s,b,c,n/2);
     
}

int main()
{
     int n;
     scanf("%d",&n);
     int s[n];
     int i;
     for(i=0;i<n;i++) scanf("%d",&s[i]);
     system("cls");
     Divide(s,n,n);
     getch();
     printf("Iste Sonuclar -->\n\n");
     for(i=0;i<n;i++) printf("%d  ",s[i]);
     getch();
}
