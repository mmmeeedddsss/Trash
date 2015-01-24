#include<stdio.h>
char s[99];

int sifrele(int x)
{
    
    int i,j,u=0;
    char de;
    s[u]=(char)x;
    scanf("%c",&de);
    puts("");
    while(s[u]!='\n')
    {
        
        u++;
        scanf("%c",&s[u]);   
    }
    s[u+1]='\n';
    u--;
    for(;u>0;u--)
    {
          i=(int)s[u];
          i=i^x;
          s[u]=(char)i;
    }
    
       
}

void coz()
{
    int i,j,x;
    x=s[0];
    for(i=1;s[i]!='\n';i++)
    {
        j=s[i];
        j=j^x;
        printf("%c",j);
        s[i]=j;
    }   
    
}

int main()
{
    int x;
    char n;
    FILE *f1;
    f1=fopen("asd.txt","w");
    //scanf("%c",&n);
    printf("Anahtari Giriniz ..\n");
    scanf("%d",&x);
    printf("Simdi Sifrelencek Seyi Gir..\n");
    sifrele(x);
    printf("%s",s);
    system("pause");
    printf("Ilk Hali..\n");
    coz();
    puts("");
    system("pause");
    //prinf("%s",s);
}
