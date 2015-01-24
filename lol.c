#include<stdio.h>
void baklava(int x)
{
     int i,j;
     for(i=0;i<x;i++){
         printf(" ");
         for(j=0;j<x;j++){
             if(i+j==4||j-i==5||i+j==14||i-j==5)
                 printf("* ");
             else
                 printf(" ");
         }
                 printf("\n");
                 }
}
void sekil(int x)
{
    for(;x<10;x++){
         printf("* ");
         }
}

int main ( )
{
    int j=0,p;
    char s;
    printf("Hangi Sekili Istiyosun ? \n");
    scanf("%c",&s);
    
    if(s=='u'){
              for(j=0;j<10;j++){
              sekil(10-j);
    printf("\n");
}
}
    else if(s=='k')
    p=0;
    else if(s=='b')
    baklava(10);
    else if(s=='d') 
    p=(-10);
    else
    printf("1 Hata Olustu ...\n");
    for(j=0;j<10;j++){
                         sekil(p);
                         printf("\n");
                         }
    
    
    /*
    switch(s){
             case 'u':
                  for(j=0;j<10;j++){
                         sekil(10-j);
                         printf("\n");
                         }
    break;
             case 'k':
                  for(j=0;j<10;j++){
                         sekil(0);
                         printf("\n");
                         }
    break;
             case 'd':
                  for(j=0;j<10;j++){
                         sekil(-10);
                         printf("\n");
                         }
    break;
              default :
                      printf("Hata Olustu ...\n");
                      }
                      */
                  
                  getch ( );
                  }
