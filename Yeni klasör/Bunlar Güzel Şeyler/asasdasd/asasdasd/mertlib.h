#include<stdio.h>
int fakt_hesapla(int x)
{
	if(x==2) return 2;
	return fakt_hesapla(x-1)*x;
}