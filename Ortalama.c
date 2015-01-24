#include<conio.h>
ebob(int x,int y)
{
         int i,p;
         if(x>y)
         p=y;
         else
         p=x;
         for(i=p;i>0;i--){
         if(i==1)
              printf("Bu 2 Sayi Birbirine Asaldir..(Ebob=1)\n");
         else if(x%i==0 && y%i==0){
              printf("Bu 2 Sayinin Ebob'u %d dir ..\n",i);
              break;
              }
              }
}

ekok(int x,int y)
{
	int ekok=1;
	int b=2;
	while( x > 1 || y > 1 ) {
		if( x%b==0 && y%b==0) {
			ekok *= b; 
			x /= b;
			y /= b;
		}
		else if( x%b==0 ) {
			ekok *= b;
			x /= b;
		}
		else if( y%b==0 ) {
			ekok *= b;
			y /= b;
		}
		else {
			b++;
		}
	}
	printf("Bu 2 Sayinin Ekok'u %d dir ...\n",ekok);
}	



int main ( )
{
         int a,b,c=1;
         char t,tkrr='e';
         while(tkrr=='e'){
         printf("Ebob Hesaplamak Icin \" b \" Ek"
         "ok Icin \" k \" Basin ...\n");
         scanf("%c",&t);
         if(t=='b'){
         printf("Ebob'unu Hesaplamak Istediin Sayilari Yaz ..\n");
         scanf("%d %d",&a,&b);
         ebob(a,b);
         }
         else if(t=='k'){
         printf("Ekok'unu Hesaplamak Istediin Sayilari Yaz ..\n");
         scanf("%d %d",&a,&b);
         ekok(a,b);
         }
         else{
         printf("Duzgun Yaz ! ...\n");
         }
         printf("Baska Sayilari da Hesaplamak Ister Misin??\n"
         "Istersen \" e \"  Istemessen \" h \" Bas... \n");
         scanf("\n%c",&tkrr);
         if(tkrr!='e')
         printf("Kullandiginiz Icin Tesekkur ...\n");
         getch( );
         }
}
