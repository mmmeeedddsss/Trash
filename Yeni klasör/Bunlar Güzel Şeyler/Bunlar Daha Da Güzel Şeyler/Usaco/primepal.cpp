/*
PROG:pprime
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

vector<int> v;
int minn,maxx;

int poww( int x, int y )
{
	int r = 1;
	for( int i=0; i<y; i++ )
		r*=x;
	return r;
}

bool isprime( int x )
{
	if( x % 2 == 0 )
		return false;
	for( int i=3; i*i<=x; i+=2 )
		if( x % i == 0 )
			return false;
	return true;
}

bool isOk( int x )
{
	if( x >= minn && x <= maxx )
		return true;
	return false;
}

int generatePals( int n )
{
	if( n % 2 == 0 )
	{
		for( long long int i=1; i<poww(10,n/2); i++ )
		{
			if( i%10 == 0 )
				continue;
			int *a = new int[n/2];
			long long int t = i;
			for( int j=n/2-1; j>=0; j-- )
			{
				a[j] = t%10;
				t/=10;
			}
			int pal = 0;
			for( int j=0; j<n/2; j++ )
			{
				pal += a[j];
				pal *= 10;
			}
			for( int j=n-1; j>=n/2; j-- )
			{
				pal += a[j-(n/2)];
				pal *= 10;
			}
			pal /= 10;
			if( isOk( pal ) && isprime( pal ) )
				v.push_back(pal);
		}
	}
	else
	{
		n--;
		for( long long int i=1; i<poww(10,n/2)+1; i++ )
		{
			for( int m=0; m<10; m++ ) // ortadaki sayý bu
			{
				int *a = new int[n/2];
				long long int t = i;
				for( int j=n/2-1; j>=0; j-- )
				{
					a[j] = t%10;
					t/=10;
				}
				int pal = 0;
				for( int j=0; j<n/2; j++ )
				{
					pal += a[j];
					pal *= 10;
				}
				pal += m;
				pal *= 10;
				for( int j=n-1; j>=n/2; j-- )
				{
					pal += a[j-(n/2)];
					pal *= 10;
				}
				pal /= 10;
				if( isOk( pal ) && isprime( pal ) )
					v.push_back(pal);
			}
		}
	}
}

int main()
{
	ifstream in("pprime.in");
	ofstream out("pprime.out");
	in>>minn>>maxx;
	for( int i=1; i<9; i++ )
		generatePals(i);
	for( int i=0; i<v.size(); i++ )
		out<<v[i]<<endl;
	out.close();
	return 0;
}
