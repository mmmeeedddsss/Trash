#include<iostream>
#include<conio.h>
#define MAX 25
using namespace std;

class ckonum{
	public:
		int x,y;
	
	ckonum()
	{
		x = y = 0;
	}
	ckonum( int _x,int _y )
	{
		x = _x;
		y = _y;
	}

};

char labirent[MAX][MAX];

int etraf_say(int y,int x)
{
	int sayac=0;
	if(labirent[y+1][x] == '.') sayac++;
	if(labirent[y][x+1] == '.') sayac++;
	if(labirent[y-1][x] == '.') sayac++;
	if(labirent[y][x-1] == '.') sayac++;
	return sayac;
}
ckonum ilerle(int y,int x)
{
	if(labirent[y+1][x] == '.') return new ckonum(x,y+1);
	if(labirent[y][x+1] == '.') return new ckonum(x+1,y);
	if(labirent[y-1][x] == '.') return new ckonum(x,y-1);
	if(labirent[y][x-1] == '.') return new ckonum(x-1,y);
}

ckonum nokta_ara(int n,int aranan)
{
	 for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
			if( labirent[j][i] == aranan-'0' )
				return new ckonum(j,i);
}

bool game_over(int n)
{
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
			if( labirent[j][i] == '.')
				return false;
	return true;
}

void cizdir(int n)
{
     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
			cout<<labirent[j][i];
}

int main()
{
	int n;
    cin>>n;
	int x,y;
	cin>>x>>y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
			cin>>labirent[j][i];
	if(labirent[y][x] != '.') exit(1);
	
	
	
	ckonum *konum = new ckonum(x,y);
	int sayac=0;
	int etraf=0;
	
	while( !game_over(n) )
	{
		if( labirent[konum->y][konum->x] = 'X' ) cizdir(n);
		etraf = etraf_say(konum->y,konum->x);
		if( etraf == 0 )
		{
			konum = &nokta_ara(n,--sayac);
		}
		else if( etraf == 1 )
		{
			labirent[konum->y][konum->x] = '*';
			konum = &ilerle(konum->y,konum->x);
		}
		else
		{
			labirent[konum->y][konum->x] = sayac-'0';
			sayac++;
			konum = &ilerle(konum->y,konum->x);
		}
	}
}



