#include<iostream>
#include<fstream>
#include<set>
#include<queue>
using namespace std;

typedef struct _node{
	int x,y;
	int val;
	int wholeWay;
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
set<int> starts;
long long int sum = 0;
int n;
int *costs;
int minn;

int calc()
{
	priority_queue<node, vector<node>, compareNodes> q;
	node temp;
	temp.x = temp.y = ('z'-'a');
	temp.val = 0;
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
		
		costs[x.x] = x.val;
		
		if( starts.find( x.x ) != starts.end() && x.x != 'Z' - 'A' )
		{
			minn = x.wholeWay;
			return x.x;
		}
		
		//cout<<x<<","<<dad<<" -> "<<a[dad][x]<<endl;
		isvisited[x.x] = true;
		for( int i=0; i<n; i++ )
			if( a[x.x][i] != 0 && isvisited[i] == false )
			{
				node tt;
				tt.x = i;
				tt.y = x.x;
				tt.val = a[x.x][i];
				tt.wholeWay = tt.val + x.wholeWay;
				q.push(tt);
			}
	}
}

int main()
{
	ifstream in("comehome.gir");
	ofstream out("comehome.cik");
	in>>n;
	costs = new int[30];
	a = new int*[30];
	for( int i=0; i<30; i++ )
		a[i] = new int[30];
	isvisited = new bool[30];
	for( int i=0; i<n; i++ )
	{
		char from,to;
		int cost;
		in>>from>>to>>cost;
		if( to >= 'A' && to <= 'Z'  )
		{
			starts.insert((int)(to - 'A') );
			to = to - 'A' + 'a';
		}
		if( from >= 'A' && from <= 'Z' )
		{
			starts.insert((int)(from - 'A') );
			from = from - 'A' + 'a';
		}
		//cout<<from<<to<<cost<<endl;
		a[(int)(from - 'a')][(int)(to - 'a')] = cost;
		a[(int)(to - 'a')][(int)(from - 'a')] = cost;
	}
	
	for( int i=0; i<30; i++ )
			isvisited[i] = false;
	
	out<<(char)(calc() + 'A' )<<" ";
	out<<minn<<endl;
	out.close();
	return 0;
}
