#include<iostream>
#include<fstream>
using namespace std;

bool *cn;

int calc( int k, int n )
{
	int index;
	while( true )
	{
		index = 2;
		while( cn[index] == true )
			index++;
		for( int i=index; i<n+1; i+=index )
		{
			if( cn[i] == false )
			{
				//cout<<i<<"  ";
				cn[i] = true;
				k--;
				if( k == 0 )
					return i;
			}
		}
	}
}

int main()
{
	ifstream in("reseto.gir");
	ofstream out("reseto.cik");
	int k,n;
	in>>n>>k;
	cn = new bool[n+1];
	for( int i=0; i<n+1; i++ )
		cn[i] = false;
	out<<calc(k,n)<<endl;
	return 0;
}
