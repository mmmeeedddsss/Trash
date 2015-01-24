#include<iostream>
using namespace std;

int main()
{
     system("cls");
     FILE *f1 = fopen("1.srt","r");
     FILE *f2 = fopen("edited.srt","w");
     char a,temp;
     while( !feof( f1 ) )
     {
          temp = ' ';
          fscanf(f1,"%c",&a);
          // ------------------------
          if( a == 'ç' )
              temp = 'c';
          else if( a == 'ý' )
               temp = 'i';
          else if( a == 'ö' )
               temp = 'o';
          else if( a == 'ü' )
               temp = 'u';
          else if( a == 'ð' )
               temp = 'g';
          else if( a == 'þ' )
               temp = 's';
          // ------------------------
          if( temp != ' ' )
               fprintf(f2,"%c",temp);
          else 
               fprintf(f2,"%c",a);
     }
     fclose(f2);
     printf("Done !\n");
     system("pause");
}
