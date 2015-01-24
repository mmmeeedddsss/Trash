#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<denemeler.h>
int main ( )
{
    char ttt[3][3];
    char devam='e';
    int sira=1,i,j,p1skor=0,p2skor=0,hamlesayaci;
    while(devam=='e'){
                      for(i=0;i<3;i++){
                                       for(j=0;j<3;j++){
                                                        ttt[i][j]=' ';
                                                        }
                                       }
                                       hamlesayaci=0;
                      while(hamlesayaci<9){
                               hamlesayaci++;
                               system("cls");
                               printf("\t\t1. Oyuncunun Skoru --> %d\n"
                               "\t\t2. Oyuncunun Skou --> %d\n",p1skor,p2skor);
                               printf("-------------------------------------------------------------\n\n\n");
                               
                               printf(
                               "     \t        |        |     \n"
                               "     \t    %c   |    %c   |    %c\n"
                               "     \t        |        |     \n"
                               "     \t---------------------------\n"
                               "     \t        |        |     \n"   
                               "     \t    %c   |    %c   |    %c\n"
                               "     \t        |        |     \n"
                               "     \t---------------------------\n"
                               "     \t        |        |      \n"
                               "     \t    %c   |    %c   |    %c\n"
                               "     \t        |        |      \n",ttt[0][0],ttt[0][1],ttt[0][2],ttt[1][0],ttt[1][1],ttt[1][2],ttt[2][0],ttt[2][1],ttt[2][2]);
                               
                               if(sira==1){
                               tekrar1:
                               scanf("%d %d",&i,&j);
                               i--;
                               j--;
                               if(ttt[i][j]=='X'||ttt[i][j]=='O'){
                                                                printf("Daha Once Buraya Girdi Girildi ..Tekrar Dene..\n");
                                                                goto tekrar1;
                               }
                               
                               ttt[i][j]='X';
                               sira=0;
                               goto kontrol;
                               }
                               
                               
                               if(sira==0){
                               tekrar2:
                               scanf("%d%d",&i,&j);
                               i--;
                               j--;
                               if(ttt[i][j]=='X'||ttt[i][j]=='O'){
                                                                printf("Daha Once Buraya Girdi Girildi ..Tekrar Dene..\n");
                                                                goto tekrar2;
                               }
                               
                               ttt[i][j]='O';
                               sira=1;
                               goto kontrol;
                               }
                               
                               kontrol:
                                       
                                       
                      for(i=0;i<3;i++){
                                       
                      if((ttt[i][0]==ttt[i][1])&&(ttt[i][0]==ttt[i][2])){
                                                                                                           
                                                        if(ttt[i][0]=='X'){
                                                                                  system("cls");
                                                                                  printf("1. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p1skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        if(ttt[i][0]=='O'){
                                                                                  system("cls");
                                                                                  printf("2. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p2skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        }
                      if((ttt[0][i]==ttt[1][i])&&(ttt[0][i]==ttt[2][i])){
                                                                                                   
                                                        if(ttt[0][i]=='X'){
                                                                                  system("cls");
                                                                                  printf("1. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p1skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        if(ttt[0][i]=='O'){
                                                                                  system("cls");
                                                                                  printf("2. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p2skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        }
                                       }
                      if((ttt[0][0]==ttt[1][1])&&(ttt[1][1]==ttt[2][2])){
                                                                         
                                                        if(ttt[0][0]=='X'){
                                                                                  system("cls");
                                                                                  printf("1. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p1skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        if(ttt[0][0]=='O'){
                                                                                  system("cls");
                                                                                  printf("2. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p2skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        }
                      if((ttt[2][0]==ttt[0][2])&&(ttt[1][1]==ttt[0][2])){
                                                                         
                                                        if(ttt[2][0]=='X'){
                                                                                  system("cls");
                                                                                  printf("1. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p1skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        if(ttt[2][0]=='O'){
                                                                                  system("cls");
                                                                                  printf("2. Oyuncu Kazandi .. Tebrikler ..\n");
                                                                                  system("pause");
                                                                                  p2skor++;
                                                                                  goto zzz;
                                                                                  }
                                                        }
                                                        
                               }
                               zzz:
                               system("cls");
                               printf("Tekrar Denemek Ister Misin?\n");
                               scanf("\n%c",&devam);
                               }
}
