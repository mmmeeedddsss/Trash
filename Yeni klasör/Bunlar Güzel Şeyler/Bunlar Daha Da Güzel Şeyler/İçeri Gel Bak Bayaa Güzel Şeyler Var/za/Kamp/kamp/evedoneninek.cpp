#include<iostream>
#include<fstream>
#include<set>
#include<queue>
using namespace std;

typedef struct _node{
	int currPos,parent;
	int val;
	int wholeWay;
}node;

class compareNodes
{
	public:
		bool operator()( node& n1, node& n2 )
		{
			return n1.wholeWay > n2.wholeWay;
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
	temp.currPos = temp.parent = ('z'-'a');
	temp.val = 0;
	temp.wholeWay = 0;
	q.push(temp);
	while( true )
	{
		node x;
		do{
			if( !q.size() )
				return 0;
			x = q.top();
			q.pop();
		}while( isvisited[x.currPos] == true );
		
		//x.wholeWay = x.val + costs[x.y];
		
		if( starts.find( x.currPos ) != starts.end() && x.currPos != 'Z' - 'A' )
		{
			minn = x.wholeWay;
			return x.currPos;
		}
		
		//cout<<x<<","<<dad<<" -> "<<a[dad][x]<<endl;
		isvisited[x.currPos] = true;
		for( int i=0; i<30; i++ )
			if( a[x.currPos][i] != 0 && isvisited[i] == false )
			{
				node tt;
				tt.currPos = i;
				tt.parent = x.currPos;
				tt.val = a[x.currPos][i];
				tt.wholeWay = tt.val + x.wholeWay;
				cout << tt.parent << " " << i << " " << tt.wholeWay << endl;
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
	for( int i=0; i<'z'-'a'; i++ )
	   for( int j=0; j<'z'-'a'; j++ )
	       a[i][j] = 0;
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
	cin>>costs[0];
	return 0;
}
