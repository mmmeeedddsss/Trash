#include<stdio.h>
// Kendisine verilen iki degiskenin 
// degerlerini degistirir.
// Parametreleri tanimlarken baslarina 
// '*' koyuyoruz.
void swap( int *x, int *y )
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int main( void )
{
	int a, b;
	a = 12;
	b = 27;
	printf( "a: %d b: %d\n", a, b );
	// Argumanları aktarırken, baslarina 
	// '&' koyuyoruz. 
	swap(&a, &b);
	printf( "a: %d b: %d\n", a, b );
	getch ( );
}
