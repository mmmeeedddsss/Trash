#include<stdio.h>
#include<math.h>
int main( void )
{
	int k1,k2,a,h;
	
	printf("Kenarlari Gir ! :D\n");
	scanf("%d%d",&k1,&k2);
	h=(k1*k1)+(k2*k2);
	h=sqrt(h);
	printf("Hipotenus = %d ' dir.\n",h);
	getch ( );
}
