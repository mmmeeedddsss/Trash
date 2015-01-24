#include <stdio.h>
#include <stdlib.h>
int main()
{
     int i,j;
     int istenen,kac_adet;
     int tum_d=0,ist_d=0;
     float sonuc;
     int *s;
     scanf("%d",&istenen);
     scanf("%d",&kac_adet);
     s=(int*)malloc(sizeof(int)*istenen);
     for(i=0;i<kac_adet;i++) scanf("%d",&s[i]);
     for(i=0;i<kac_adet;i++)
     {
          for(j=(1+i);j<kac_adet;j++)
          {
               if(s[i] >= istenen || s[j]-s[i] >= istenen || 100-s[j] >= istenen) ist_d++;
          }
     }
     tum_d = ((kac_adet*(kac_adet-1)) / 2);  // C(kac_adet,2);
     sonuc=(float)ist_d/tum_d;
     printf("%f",sonuc);
     return 0;
}
