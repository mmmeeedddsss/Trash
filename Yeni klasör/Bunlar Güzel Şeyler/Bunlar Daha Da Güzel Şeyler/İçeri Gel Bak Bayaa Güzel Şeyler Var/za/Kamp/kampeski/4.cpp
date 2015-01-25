#include<iostream>
#include<fstream>
using namespace std;

int **values;
bool *colors;
int *track;

int start, finish;
int n;
int step=0,max_step;

int *max_track;
int maxval = 0;

int calc( int pos, int dad_node, int point )
{
	if( pos == finish )
	{
		if( maxval < point )
		{
			maxval = point;
			max_track[pos] = dad_node;
		}
	}
	
	for( int i=0; i<n; i++ )
	{
		if( values[pos][i] != 0 && colors[i] == false )
		{
			colors[i] = true;
			if( calc(i, pos, point + values[pos][i] ))
				max_track[pos] = dad_node;
			colors[i] = false;
		}
	}
	return point;
}

int getInput()
{
	ifstream in("alavere.gir");
	int m;
	cin>>n>>m;
	values = new int*[n];
	for( int i=0; i<n; i++ )
		values[i] = new int[n];
	colors = new bool[n];
	track = new int[n];

	char from,to;
	int x,y;
	int value;
	for( int i=0; i<m; i++ )
	{
		cin>>from>>to;
		cin>>value;
		x = (int)(from - 'A');
		y = (int)(to - 'A');
		values[x][y] = value;
		values[y][x] = value;
	}
	char cstart,cfinish;
	cin>>cstart>>cfinish;
	start = cstart - 'A';
	finish = cfinish - 'A';
	colors[start] = true;
	max_track = new int[n];
	//cout<<finish<<" - "<<start;
	
}

int main()
{
	getInput();
	calc(start,-1,0);
	ofstream out("alavere.cik");
	
	int k = finish;
	while( max_track[k] != -1 )
	{
		cout<<(char)(max_track[k] + 'A')<<"-";
		k = max_track[k];
	}
	cout<<(char)(start+'A');
	
	cout<<" : ";
	cout<<maxval<<endl;
	return 0;
}
