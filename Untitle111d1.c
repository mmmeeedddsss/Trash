#include<stdio.h>
int main ( )

{
    int a[11]={0,1,2,3,4,5,6,7,8,9,10};
    int i,j,gecici,p=11;
    printf("Dizinin Ilk Hali...\n");
    for(i=0;i<11;i++){
           printf("%d ",a[i]);
           }
           getch ( );
           printf("\n");
    for(i=0;i<6;i++){
           gecici=a[p];
           a[p]=a[i];
           a[i]=gecici;
           p--;
           }
    for(i=0;i<11;i++){
           printf("%d ",a[i+1]);
           }
           getch ( );
}
           
