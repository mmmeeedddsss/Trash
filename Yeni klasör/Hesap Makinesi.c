#include<stdio.h>
int main( void )
{
    int a,*p,**p2,i;
    p2=&p;
    for(i=0;i<2;i++){
    scanf("%d",&a);
    printf("\n%p\n",p);
    p=&a;
    p--;;
    }
    p-=2;
    for(i=0;i<6;i++)
    {
    printf("\n%p\n",*p2);
    printf("%d\n\n",**p2);
    p++;
    }
    getch();
    
}
