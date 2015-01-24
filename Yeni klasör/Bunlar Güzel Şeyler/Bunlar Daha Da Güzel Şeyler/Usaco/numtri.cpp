/*
PROG:numtri
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

int tri[1000][1000];
int n;

int calc()
{
	for( int i=n-1; i>0; i-- )
		for( int j=0; j<i; j++ )
			tri[j][i-1] += max( tri[j][i], tri[j+1][i] );
}

int main()
{
	ifstream in("numtri.in");
	ofstream out("numtri.out");
	in>>n;
	for( int i=0; i<n; i++ )
		for( int j=0; j<i+1; j++ )
			in>>tri[j][i];
	calc();
	out<<tri[0][0]<<endl;
	out.close();
	return 0;
}
