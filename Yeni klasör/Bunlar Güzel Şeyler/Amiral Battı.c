#include<stdio.h>
int main()
{

    char gdizi[8][8];
    char tahta[8][8];
    int i,life=14,j,a,b,denemesayisi=0;
    for(i=0;i<8;i++)
    {
                      for(j=0;j<8;j++)
                      {
                                       gdizi[i][j]=' ';
                                       tahta[i][j]=' ';
                      }
    }
    srand(time(NULL));
    for(i=0;i<3;i++)
    {
    a=rand()%7;
    b=rand()%7;
    gdizi[a][b]='X';
    }
    
    for(i=0;i<2;i++)
    {
    a=rand()%7;
    b=rand()%7;
    gdizi[a][b]='X';
    gdizi[a+1][b]='X';
    }
    a=rand()%7;
    b=rand()%7;
    gdizi[a][b]='X';
    gdizi[a][b+1]='X';
    gdizi[a][b+2]='X';
    //-----------------------------------------------
    a=rand()%7;
    b=rand()%7;
    gdizi[a][b]='X';
    gdizi[a][b+1]='X';
    gdizi[a][b+2]='X';
    gdizi[a][b+3]='X';
    //-----------------------------------------------


    while(life>0)
    {
                 system("cls");
                 printf("\t\t\tDeneme Sayin ---> %d\n\t\t\tKalan Gemi Sayisi ---> %d",denemesayisi,life);
                 printf("\n================================================================================\n\n");
                 printf("\n\t\t  1    2    3    4    5    6    7    8");
    for(i=0;i<8;i++)
    {                                                                                                             
                    
                     printf("\n\t\t----------------------------------------\n\t      %d ",i+1);
                     for(j=0;j<8;j++)
                     {
                              printf("| %c |",tahta[i][j]);
                     }
    }
    printf("\n\t\t----------------------------------------\n");
    
    zzz:
    scanf("%d%d",&i,&j);
    i--;
    j--;
    if(gdizi[i][j]=='Y'||j>7||i>7)
    {
                            printf("Hata..Tekrar Deneyiniz..\n");
                            
                            goto zzz;
    }
    if(gdizi[i][j]=='X')
    {
                            life--;
                            system("cls");
                            printf("Vurdunuz !!! ...\n");
                            system("pause");
                            system("cls");
                            denemesayisi++;
                            tahta[i][j]='X';
                            gdizi[i][j]='Y';
                            continue;
    }
    else
    {
        denemesayisi++;
        gdizi[i][j]='Y';
        tahta[i][j]='O';
        continue;
    }
    }
                            
    
}










