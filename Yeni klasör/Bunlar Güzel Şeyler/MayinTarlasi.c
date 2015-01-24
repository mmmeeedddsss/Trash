#include <stdio.h>
#include <stdlib.h>
#define en 10
#define boy 10
int main ()
{
	int u,i,j,k1=3,k2=4,mayinsayisi=0;
	char s[boy][en],a;
	char mayinlar[boy][en];
	char cevaplar[boy][en];
	srand(time(NULL));
	for(i=0;i<boy;i++)
	{
		for(j=0;j<en;j++)
		{
			s[i][j]=' ';
			mayinlar[i][j]=' ';
		}
	}

	//-----------------------------------------------------------
	
	for(u=0;u<20;u++)
	{	

zzz:
		i=rand()%(boy-1);
		j=rand()%(en-1);
		if(mayinlar[i][j]==' ')
		mayinlar[i][j]='*';
		else goto zzz;
	}
	/*
	for(i=0;i<boy;i++)
	{
		printf("\n-------------------------------------------\n|");
		for(j=0;j<en;j++)
		{
			printf(" %c |",mayinlar[i][j]);
		}
	}
	*/
	
	//-----------------------------------------------------------

	printf("Kurallar --> \n"
	"- 10x10 luk Duzlemde 20 Adet Mayain Bulunmaktadir..\n"
	"- 20 Bayraktan Fazla Konulamaz..\n"
	"- Bayrak Koymak icin b,\n"
	"- Kutu Acmak icin i,\n"
	"- 20 Bayragi Yerlestirdikten Sonra ,\nKontroll Etmek icin k Giriniz..\n\n");
	system("pause");
	s[3][4]='X';
	system("color 8");
	while(1)
	{
	bitis:
    system("cls");
	for(i=0;i<boy;i++)
	{
		printf("\n-----------------------------------------\n|");
		for(j=0;j<en;j++)
		{
			printf(" %c |",s[i][j]);
			if(i==4&&j==9) printf("  Kullanilan Bayrak Sayisi ---> %d",mayinsayisi);
			if(i==9&&j==9) printf("\t\t\t>>By Mert<<");
		}
	}
	printf("\n-----------------------------------------");

	a=getch();


	if(a=='k')
	{
		for(i=0;i<boy;i++)
		{
			for(j=0;j<en;j++)
			{
				if(mayinlar[i][j]=='*')
				{	
					if(s[i][j]=='B') continue;
					else
					{
						printf("\nGame Over .. [%d] [%d] Kordinatlarindaki Bayrak Uyusmuyor..\n",i+1,j+1);
						system("pause");
						goto pff;
					}
				}
			}
		}
	}



	
	
	if(a=='i')
	{

	
		if(mayinlar[k1][k2]=='*')
		{
             
pff:
             system("cls");
             
             
	for(i=0;i<boy;i++)
	{
		printf("\n-------------------------------------------\n|");
		for(j=0;j<en;j++)
		{
            if(mayinlar[i][j]=='*') cevaplar[i][j]='*';
            else cevaplar[i][j]=s[i][j];
			printf(" %c |",cevaplar[i][j]);
			if(i==5&&j==9) printf("   Game Over ..");
		}
	}
	getch();
	return 0;
	}


	
		i=0;
		if(mayinlar[k1+1][k2]=='*') i++;
		if(mayinlar[k1][k2+1]=='*') i++;
		if(mayinlar[k1-1][k2]=='*') i++;
		if(mayinlar[k1][k2-1]=='*') i++;
		if(mayinlar[k1+1][k2+1]=='*') i++;
		if(mayinlar[k1-1][k2-1]=='*')i++;
		if(mayinlar[k1+1][k2-1]=='*') i++;
		if(mayinlar[k1-1][k2+1]=='*') i++;
		
		s[k1][k2]=i+'0';
		goto bitis;
	
	}

	//------------------------------------------------------------
	
	switch(a)
	{
		case'w':  if(s[k1][k2]=='X') s[k1][k2]=' '; if(k1>0) k1--; if(s[k1][k2]==' ') s[k1][k2]='X'; break;
		case's':  if(s[k1][k2]=='X') s[k1][k2]=' '; if(k1<9) k1++; if(s[k1][k2]==' ') s[k1][k2]='X'; break;
		case'a':  if(s[k1][k2]=='X') s[k1][k2]=' '; if(k2>0) k2--; if(s[k1][k2]==' ') s[k1][k2]='X'; break;
		case'd':  if(s[k1][k2]=='X') s[k1][k2]=' '; if(k2<9) k2++; if(s[k1][k2]==' ') s[k1][k2]='X'; break;
		case'b':  if(s[k1][k2]!='X') goto trallaaa;if(mayinsayisi<20)s[k1][k2]=' '-30; mayinsayisi++; trallaaa: break;
	}

	//-------------------------------------------------------------
	
	}
	
}


















