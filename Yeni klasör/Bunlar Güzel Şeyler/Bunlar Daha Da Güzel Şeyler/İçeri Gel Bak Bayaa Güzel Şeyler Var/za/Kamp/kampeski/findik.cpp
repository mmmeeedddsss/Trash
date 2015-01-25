#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int count( string s )
{
	if( s.size() < 2 )
		return s.size();
	int counter = 0;
	for( int i=0; i<s.size()-1; i++ )
	{
		if( s[i] == 'c' && s[i+1] == '-')
			counter++;
		if( s[i] == 'd' && s[i+1] == '-')
			counter++;
		if( s[i] == 's' && s[i+1] == '=')
			counter++;
		if( s[i] == 'c' && s[i+1] == '=')
			counter++;
		if( s[i] == 'l' && s[i+1] == 'j')
			counter++;
		if( s[i] == 'n' && s[i+1] == 'j')
			counter++;
	}
	int c1=0,c2=0;
	for( int i=0; i<s.size()-2; i++ )
	{
		if( s[i] == 'z' && s[i+1] == '=')
			c1++;
		if( s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=' )
			c2++;
	}
	if( s[s.size()-2] == 'z' && s[s.size()-1] == '=')
		c1++;
	c1 -= c2;
	c2 *= 2 ;
	if( c1<0 )
		c1=0;
	
	return ( s.size()-counter-c1-c2 );
		
}

int main()
{
	ofstream out("ljesnjak.cik");
	ifstream in("ljesnjak.gir");
	string s;
	in>>s;
	out<<count(s);
}
