#include<iostream>
#include<fstream>
using namespace std;
int n;
int **a;

int calc( int n ) // ninci satýrda n+1 eleman var
{
	if( n == -1 )
		return a[0][0];
	for( int i=0; i<n+1; i++ )
		a[n][i] += (( a[n+1][i] > a[n+1][i+1] )? a[n+1][i+1] : a[n+1][i]);
	return calc(n-1);
}


int main()
{
	cin>>n;
	a = new int*[n];
	for( int i=0; i<n; i++ )
		a[i] = new int[n];
	for( int i=0; i<n; i++ )
		for( int j=0; j<i+1; j++ )
			cin>>a[i][j];
	cout<<calc(n-2)<<endl;
}