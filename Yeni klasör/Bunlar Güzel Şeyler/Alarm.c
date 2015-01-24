#include<stdio.h>
#include<windows.h>
int main ()
{
    int x;
    scanf("%d",&x);
    x*=1000;
    Sleep(x);
    while(!kbhit()) {  printf("\a"); Sleep(500); }
      
    
}
