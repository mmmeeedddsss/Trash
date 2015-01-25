#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("badhair.gir");
	ofstream out("badhair.cik");
	int n;
	in>>n;
	int *a = new int[n];
	for( int i=0; i<n; i++ )
		in>>a[i];

	int sum = 0;
	for( int i=0; i<n; i++ )
	{
		for( int j=i+1; j<n+1; j++ )
			if( a[i] <= a[j] || j == n )
			{
				sum += j-i-1;
				break;
			}
				
	}
	out<<sum;
				
}
