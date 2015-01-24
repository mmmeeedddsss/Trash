#include<stdio.h>
/*
int sort(x,y)
{
     if(x>y) return x;
     return y;
}
/*
int varilmadi(int x,int amac)
{
     int adim=1;
     while(x<amac)
     {
         x+=adim;
         adim++;
     }
     return x;
}
*/
int parcala(int x,int y)
{
     int varis_noktasi,save;

     int sayac=0;
     varis_noktasi=((y-x)/2)+x;
     //printf("%d %d\n",x,y);
     //x=varilmadi(x,varis_noktasi);
     
     int adim=1;
    //printf("%d %d\n",x,varis_noktasi);
     while(x<varis_noktasi)
     {
         x+=adim;
         adim++;
         sayac++;
        // printf("asdasdasd\n");
     }
     //printf("%d\n",sayac);
     if((y-x)%2&&adim>2) adim-=2;
     //printf("%d %d %d",x,y,adim);  // 31 5 36 40 43 46 48 49 50
     
     while(x<y)
     {
          x+=adim;
          if(adim>1)adim--;
          sayac++;
          if(x==y) return sayac;
     }
     if(adim==1) return sayac;
     return ++sayac;
     
}

int main()
{
     int x,y;
     scanf("%d%d",&x,&y);
     printf("\n%d\n",parcala(x,y));
     getch();
}
