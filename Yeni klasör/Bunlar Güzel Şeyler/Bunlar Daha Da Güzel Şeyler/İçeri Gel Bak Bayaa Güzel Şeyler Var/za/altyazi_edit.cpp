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
          if( a == '�' )
              temp = 'c';
          else if( a == '�' )
               temp = 'i';
          else if( a == '�' )
               temp = 'o';
          else if( a == '�' )
               temp = 'u';
          else if( a == '�' )
               temp = 'g';
          else if( a == '�' )
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
