#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char *s;
int n,k;
int counter = 0;
bool *changed;

bool isok()
{
	for( int i=1; i<n+1; i++ )
	{
		if( s[i-1] == s[i] )
		{
			return false;
		}
	}
	return true;
}

char getNext( char c, int index )
{
	if( changed[index] == false )
	{
		changed[index] = true;
		counter++;
	}
	
	if( ( (c+1) - 'A' ) >= k )
		return 'A';
	else
		return (char)(c+1);
}

char getAvaible( int index )
{
	if( changed[index] == false )
	{
		changed[index] = true;
		counter++;
	}
	for( int i=0; i<k; i++ )
		if( (s[index-1] != ((char)(i + 'A'))) && (((char)(i + 'A')) != s[index+1]) )
			return ((char)(i+'A'));
}

int calc()
{
	while( !isok() )
	{
		for( int i=2; i<n; i++ )
		{
			if( s[i-1] == s[i] && s[i] == s[i+1] && s[i-1] == s[i+1] )
			{
				s[i] = getAvaible(i);
				i++;
			}
		}
		for( int i=n-1; i>=1; i-- )
		{
			if( s[i+1] == s[i] )
			{
				s[i+1] = getAvaible(i+1);
			}
		}
	}
	return 0;
}

int main()
{
	ofstream out("serit.cik");
	ifstream in("serit.gir");
	in>>n>>k;
	s = new char[n+2];
	changed = new bool[n+2];
	for( int i=0; i<n; i++ )
		changed[i] = false;
	s[0] = '1';
	s[n+1] = '1';
	for( int i=1; i<n+1; i++ )
		in>>s[i];
	calc();
	out<<counter<<endl;
	for( int i=1; i<n+1; i++ )
		out<<s[i];
	out.close();
	return 0;
}
