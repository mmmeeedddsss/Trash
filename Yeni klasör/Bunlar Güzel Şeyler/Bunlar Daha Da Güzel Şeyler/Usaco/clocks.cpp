/*
PROG:clocks
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int powwa[10];

int poww( int x, int y )
{
    if( powwa[y] != 0 )
        return powwa[y];
	int r = 1;
	for( int i=0; i<y; i++ )
		r*=x;
    powwa[y] = r;
	return r;
}

bool isok( int n )
{
	if( n == 444444444 )
		return true;
	return false;
}

int getDigit( int n, int d )
{
	return ((n/poww(10,d-1))%10);
}

int simplfy( int n )
{
	for( int i=0; i<9; i++ )
		if( getDigit(n,i+1) > 4 )
			n -= 4*poww(10,i--);
	return n;
}

int turn( int wo )
{
	switch( wo )
	{
		case 1: return 110110000; //
		case 2: return 111000000; //
		case 3: return 11011000;//
		case 4: return 100100100;//
		case 5: return 10111010;//
		case 6: return 1001001;//
		case 7: return 110110;//
		case 8: return 111;//
		case 9: return 11011;//
	}
}

int calc( int n )
{
	vector<int> v;
	int lim = 4*4*4*4*4*4*4*4*4;
	int add[9];
	for( int i=0; i<lim; i++ )
	{
		int tn = n;
		int ti = i;
		for( int j=0; j<9; j++ )
		{
			add[j] = ti%4;
			ti/=4;
		}
		for( int j=1; j<10; j++ )
		{
			if( add[j-1] > 0 )
			{
				for( int m=0; m<add[j-1]; m++ )
					tn += turn( j );
				tn = simplfy( tn );
			}
		}
		if( isok( tn ) )
			v.push_back(i);
	}
	int minn = 999999;
	int minNum = 0;
	for( int i=0; i<v.size(); i++ )
	{
		int ti = v[i];
		for( int j=0; j<9; j++ )
		{
			add[j] = ti%4;
			ti/=4;
		}
		int sum = 0;
		for( int j=0; j<9; j++ )
			sum += add[j];
		if( sum < minn )
		{
			minn = sum;
			minNum = v[i];
		}
    }
	return minNum;
}

int main()
{
    ifstream in("clocks.in");
	ofstream out("clocks.out");
	int t;
	int s = 0;
	for( int i=0; i<9; i++ )
	{
		in>>t;
		t/= 3;
		s*=10;
		s+= t;
	}
	int a = calc(s);
	int add[9];
	vector<int> v;
	for( int j=0; j<9; j++ )
	{
		add[j] = a%4;
		a/=4;
	}
	for( int i=0; i<9; i++ )
		for( int j=0; j<add[i]; j++ )
			v.push_back(i+1);
	for( int i=0; i<v.size()-1; i++ )
		out<<v[i]<<" ";
	out<<v[v.size()-1]<<endl;
	out.close();
    return 0;
}
