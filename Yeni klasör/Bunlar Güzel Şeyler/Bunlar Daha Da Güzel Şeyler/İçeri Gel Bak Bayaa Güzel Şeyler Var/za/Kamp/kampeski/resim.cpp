#include<iostream>
#include<fstream>
using namespace std;

char **a;

int getWhiteCount( int x, int y, int range )
{
	int count = 0;
	for( int i=x; i<range+x; i++ )
		for( int j=y; j<range+y; j++ )
			if( a[i][j] == '1' )
				count++;
	return count;
}

int getBlackCount( int x, int y, int range )
{
	int count = 0;
	for( int i=x; i<range+x; i++ )
		for( int j=y; j<range+y; j++ )
			if( a[i][j] == '0' )
				count++;
	return count;
}

int calc( int x, int y, int range )
{
	if(range==1)
		return 0;
	int minn = 512*512;
	int errorW[4],errorB[4];
	int errors[4];
	for( int i=0; i<4; i++ )
	{
		errors[i] = -1;
		errorW[i] = getBlackCount( (i%2)*(range/2)+x, (i/2)*(range/2)+y, (range/2) );
		errorB[i] = getWhiteCount( (i%2)*(range/2)+x, (i/2)*(range/2)+y, (range/2) );
	}
	for( int i=0; i<4; i++ ) // siyaha boyanacak olan -> i
	{
		for( int j=0; j<4; j++ ) // beyaz
		{
			if( i != j )
			{
				int error = 0;
				//if( errorB == 0 || errorW == 0 )
					//cout<<"Handle It !!"<<endl;
				error += errorB[j] + errorW[i];
				for( int m=0; m<4; m++ )
					if( i != m && j != m )
					{
						if(errors[m] == -1)
							errors[m] = calc( (m%2)*(range/2)+x, (m/2)*(range/2)+y, (range/2));
						error += errors[m];
					}
				if( minn > error )
					minn = error;
			}
		}
	}
	return minn;
}

int main()
{
	ifstream in("Slikar.gir");
	ofstream out("Slikar.cik");
	int n;
	in>>n;
	a = new char*[n];
	for( int i=0; i<n; i++ )
		a[i] = new char[n];
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
		{
			in>>a[i][j];
		}
	out<<calc( 0,0,n )<<endl;
	
}
