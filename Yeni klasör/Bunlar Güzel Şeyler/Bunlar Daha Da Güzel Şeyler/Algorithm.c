#include<stdio.h>
int main()
{
    int i,temp;
    unsigned long long int cevap;
    scanf("%d",&i);
    temp=i;
    for(;temp;temp--)
    {
          if(!(i%temp)){ cevap++;
          //printf("%d",temp);
          }
    }
    if(cevap%2) printf("Acik\n\n");
    else printf("Kapali\n\n");
    getch();
}
