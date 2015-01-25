#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char paint[512][512];


int boyabeyaz(int N,int x,int y)
{
    int hata=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(paint[i+x][j+y]=='1')
                hata++;
    return hata;
}

int boyasiyah(int N,int x,int y)
{
    int hata=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(paint[i+x][j+y]=='0')
                hata++;
    return hata;
}

int boya(int N,int x,int y)
{
    if(N==1)
        return 0;

    int beyazhatalar[4],siyahhatalar[4],direkhatalar[4];
    for(int i=0;i<4;i++)
    {
        direkhatalar[i]=-1;
        beyazhatalar[i]=boyasiyah(N/2,x+(i%2)*(N/2),y+ (i/2)*(N/2));
        siyahhatalar[i]=boyabeyaz(N/2,x+(i%2)*(N/2),y+(i/2)*(N/2));
    }

    int hatason=512*512,hatailk=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(i!=j)
            {
                for(int k=0;k<4;k++)
                    if(k!=i && k!=j && direkhatalar[k]==-1)
                       {
                            direkhatalar[k]=boya(N/2,x+(i%2)*(N/2),y+ (i/2)*(N/2));
                       }
                for(int k=0;k<4;k++)
                    if(k!=i && k!=j)
                        hatailk+=direkhatalar[k];

                hatason=(hatason<(hatailk+beyazhatalar[i]+siyahhatalar[j]))?hatason:(hatailk+beyazhatalar[i]+siyahhatalar[j]);
                hatailk=0;
            }

    return hatason;
}
    main()
{
    freopen("slikar.gir","r",stdin);
    freopen("slikar.cik","w",stdout);

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>paint[i][j];
    boya(N,0,0);
}

