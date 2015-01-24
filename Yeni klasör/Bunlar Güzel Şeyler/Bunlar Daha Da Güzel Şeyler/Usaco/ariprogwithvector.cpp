/*
PROG:ariprog
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;

set<int> st;
vector<int> v;

int generateBises( int m )
{
	for( int i=0; i<=m; i++ )
		for( int j=0; j<=m; j++ )
			st.insert( i*i + j*j );
    set<int>::iterator i;
	for( i=st.begin(); i!=st.end(); i++ )
	     v.push_back(*i);
	sort( v.begin(), v.end() );
	return 0;
}

int containingPos( int val, int s )
{
	int ind = 0;
	while( v[s+ind] < val )
		ind++;
	if( v[ s+ind ] == val )
		return s+ind;
	return -1;
}

class comp{
	public:
		bool operator()( pair<int,int> a, pair<int,int> b )
		{
			if( a.second > b.second )
				return true;
			if( a.second == b.second && a.first > b.first )
			    return true;
			return false;
		}
};

priority_queue<pair<int,int>,vector<pair<int,int> >,comp> q;

int findAriProgs( int n )
{
	int lim = v.size();
	for( int i=0; i<lim; i++ )
	{
		int a = v[i];
		int b;
		for( int j=i+1; j<lim-n+2; j++ )
		{
			int len = 2;
			int b = v[j] - v[i];
			int pos = j;
			while( len < n ) //  !
			{
				pos = containingPos( a + ( len*b ), pos + 1 ); // J+1 DEN ITIBAREN
				if( pos != -1 )
					len++;
				else 
					break;
			}
			if( len == n )
				q.push( make_pair( a,b ) );
		}
	}
}

int main()
{
	ifstream in("ariprog.in");
	ofstream out("ariprog.out");
	int n,m; // n-> uzunluk, m-> p,q upper
	in>>n>>m;
	generateBises(m);
	findAriProgs(n);
	if( q.empty() )
		out<<"NONE"<<endl;
	while( !q.empty() )
	{
		pair<int,int> p = q.top();
		out<<p.first<<" "<<p.second<<endl;
		q.pop();
	}
	out.close();
	return 0;
}
