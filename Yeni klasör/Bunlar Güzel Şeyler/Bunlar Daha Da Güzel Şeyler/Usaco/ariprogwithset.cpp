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

int generateBises( int m )
{
	for( int i=0; i<=m; i++ )
		for( int j=0; j<=m; j++ )
			st.insert( i*i + j*j );
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

int findAriProgs( int n )
{
	int lim = st.size();
	for( set<int>::iterator it=st.begin(); it!=st.end(); it++ )
	{
		int a = *it;
		int b;
		for( set<int>::iterator j=it;; )
		{
			if( ++j == st.end() )
				break;
			int len = 2;
			int b = *j - *it;
			while( len < n ) //  !
			{
				if( st.count( a + (len*b) ) != 0 )
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
