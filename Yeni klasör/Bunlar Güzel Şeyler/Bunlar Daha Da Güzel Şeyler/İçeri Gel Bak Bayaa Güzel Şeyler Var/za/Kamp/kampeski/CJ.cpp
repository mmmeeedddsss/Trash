#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

typedef struct _node{
	int x,y;
	int val;
}node;

class compareNodes
{
	public:
		bool operator()( node& n1, node& n2 )
		{
			return n1.val > n2.val;
		}
};

int **a;
bool *isvisited;
long long int sum = 0;
int n;

int calc()
{
	priority_queue<node, vector<node>, compareNodes> q;
	node temp;
	temp.x = temp.y = temp.val = 0;
	q.push(temp);
	while( true )
	{
		node x;
		do{
			if( !q.size() )
				return 0;
			x = q.top();
			q.pop();
		}while( isvisited[x.x] == true );
		sum += x.val;
		//cout<<x<<","<<dad<<" -> "<<a[dad][x]<<endl;
		isvisited[x.x] = true; // hatalı
		for( int i=0; i<n; i++ )
			if( a[x.x][i] != 0 && isvisited[i] == false ) // hatalı
			{
				node tt;
				tt.x = i;
				tt.y = x.x;
				tt.val = a[x.x][i];
				q.push(tt);
			}
	}
}

int main()
{
	ifstream in("agrinet.gir");
	ofstream out("agrinet.cik");
	in>>n;
	isvisited = new bool[n];
	a = new int*[n];
	for( int i=0; i<n; i++ )
	{
		a[i] = new int[n];
		isvisited[i] = false;
	}
	
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
		{
			in>>a[i][j];
			a[j][i] = a[i][j];
		}
	calc();
	out<<sum<<endl;
	return 0;
}
