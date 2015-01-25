#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string a;

unsigned long long int calc( int pos, unsigned long long int point )
{
	if( pos == a.size() )
		return point;
	if( a[pos] == 'L' )
		return calc( pos + 1, 2*point );
	if( a[pos] == 'R' )
		return calc( pos + 1, 2*point + 1 );
	if( a[pos] == 'P' )
		return calc( pos + 1, point );
	else
		return calc( pos + 1, point ) + calc( pos + 1, 2*point ) + calc( pos + 1, 2*point + 1 );
}

int main()
{
	ofstream out("setnja.cik");
	ifstream in("setnja.gir");
	cin>>a;
	cout<<calc(0,1)<<endl;
	out.close();
}
