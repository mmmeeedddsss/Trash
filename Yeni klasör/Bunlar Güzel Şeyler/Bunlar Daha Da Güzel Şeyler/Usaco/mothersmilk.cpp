/*
PROG:milk3
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

int capa,capb,capc;
bool da[21][21][21];
set<int> s;

int calc( int a, int b, int c )
{
	if( da[a][b][c] == true )
		return 0;
	da[a][b][c] = true;
	if( a == 0 )
		s.insert(c);
	
	if( a != 0 )
	{
		int t = a+b;
		if( capb > t )
			calc(0,t,c);
		else
			calc(t-capb,capb,c);
			
		t = a+c;
		if( capc > t )
			calc(0,b,t);
		else
			calc(t-capc,b,capc);
	}
	
	if( b != 0 )
	{
		int t = b+a;
		if( capa > t )
			calc(t,0,c);
		else
			calc(capa,t-capa,c);
			
		t = b+c;
		if( capc > t )
			calc(a,0,t);
		else
			calc(a,t-capc,capc);
	}
	
	if( c != 0 )
	{
		int t = c+b;
		if( capb > t )
			calc(a,t,0);
		else
			calc(a,capb,t-capb);
			
		t = c+a;
		if( capa > t )
			calc(t,b,0);
		else
			calc(capa,b,t-capa);
	}
}

int main()
{
	ifstream in("milk3.in");
	ofstream out("milk3.out");
	in>>capa>>capb>>capc;
	calc(0,0,capc);
	set<int>::iterator it;
	vector<int> v;
	for(it = s.begin();it != s.end();it++)
		v.push_back(*it);
	for( int i=0; i<v.size()-1; i++ )
		out<<v[i]<<" ";
	out<<v[v.size()-1]<<endl;
	out.close();
	return 0;
}
