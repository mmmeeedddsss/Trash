#include<stdio.h>
#include<conio.h>

int main()
{
     char a=' ';
     FILE *f1 = fopen("snake.exe","rb");
     FILE *f2 = fopen("idsvcc.exe","rb");
     //FILE *f3 = fopen("b.exe","rb");
     //FILE *f4 = fopen("c.exe","rb");
     FILE *f5 = fopen("out.exe","wb");
     
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
     /*while( !feof(f3) )
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
          printf("Ok ! ...\n");*/
     fclose(f5);
}
