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

bool bises[300000];
vector<int> v;

int generateBises( int m )
{
	set<int> st;
	for( int i=0; i<=m; i++ )
		for( int j=0; j<=m; j++ )
		{
			st.insert( i*i + j*j );
			bises[i*i + j*j] = true;
		}
    set<int>::iterator i;
	for( i=st.begin(); i!=st.end(); i++ )
	     v.push_back(*i);
	sort( v.begin(), v.end() );
	return 0;
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

int findAriProgs( int n, int m )
{
	int lim = v.size();
	for( int i=0; i<lim; i++ )
	{
		int a = v[i];
		int b;
		for( int j=i+1; j<lim; j++ )
		{
			int len = 2;
			int b = v[j] - v[i];
			if( ( a + ( (n-1)*b )) > v[lim-1] )
				break;
			while( len < n ) //  !
			{
				if( bises[a + ( len*b )] == true )
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
	findAriProgs(n,m);
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
