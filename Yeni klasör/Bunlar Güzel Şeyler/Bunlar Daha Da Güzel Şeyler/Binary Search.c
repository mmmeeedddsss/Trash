#include<stdio.h>
int BinarySearch(int *s,int l,int r,int A)
{
     if(l>r) return -2;
     int m;
     m=(l+r)/2;
     if(A==s[m]) return m;
     if(A>s[m]) l=m+1;
     else r=m-1;
     return BinarySearch(s,l,r,A);
}

void generate()
{
     FILE *f1;
     f1=fopen("dosya.txt","w");
     unsigned long long int x;
     for(x=0;x<100000;x++) fprintf(f1,"%llu\n",x);
     fclose(f1);
}
int main()
{
     int x;
     generate();
     system("pause");
     scanf("%d",&x);
     int i,A;
     int s[x];
     for(i=0;i<x;i++) scanf("%d",&s[i]);
     scanf("%d",&A);
     puts("\n");
     printf("%d\n",1+BinarySearch(s,0,x-1,A));
     getch();    
}
