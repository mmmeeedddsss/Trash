#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int end;

typedef struct _st{
	int state;
	string moveComb;
}pr;

int A( int pos )
{
	int newPos = 0;
	for( int i=0; i<8; i++ )
	{
		newPos += pos%10;
		pos /= 10;
		newPos *= 10;
	}
	return newPos/10;
}

int B( int pos )
{
	int a = ( pos/10000 ) % 10;
	int b = ( pos/1000 ) % 10;
	int newPos = a;
	newPos *= 1000000;
	newPos += ( pos/100000 )*1000;
	newPos += ( pos%1000 );
	newPos *= 10;
	newPos += b;
	return newPos;
}

int C( int pos )
{
	int a[8],newPos=0;
	int i=7;
	while( pos > 0 )
	{
		a[i--] = pos%10;
		pos/=10;
	}
	
	int temp = a[1];//1 - 2
	a[1] = a[2];
	a[2] = temp;
	temp = a[1];//1 - 5
	a[1] = a[5];
	a[5] = temp;
	temp = a[1];//1 - 6
	a[1] = a[6];
	a[6] = temp;
	
	for( i=0; i<8; i++ )
	{
		newPos += a[i];
		newPos *=10;
	}
	return newPos/10;
}

pr initStruct(int state, string comb)
{
	pr temp;
	temp.state = state;
	temp.moveComb = comb;
	return temp;
}

bool isContains( vector<int> vN, int cs )
{
	for( int i=0; i<vN.size(); i++ )
		if( vN[i] == cs )
			return true;
	return false;
}

string calc(int start)
{
	queue<pr> nextPositions;
	vector<int> visitedNodes;
	nextPositions.push( initStruct(start, "") );
	
	while( !nextPositions.empty() )
	{
		pr curr = nextPositions.front();
		nextPositions.pop();
		
		if( isContains( visitedNodes, curr.state ) )
			continue;
		
		visitedNodes.push_back( curr.state );
		
		if( curr.state == end )
			return curr.moveComb;
			
		nextPositions.push( initStruct( A(curr.state), ( curr.moveComb + "A") ) );
		nextPositions.push( initStruct( B(curr.state), ( curr.moveComb + "B") ) );
		nextPositions.push( initStruct( C(curr.state), ( curr.moveComb + "C") ) );
	}
}

int main()
{
	end=0;
	for( int i=0; i<8; i++ )
	{
		int temp;
		cin>>temp;
		end+=temp;
		end*=10;
	}
	end/=10;
	string s = calc(12345678);
	cout<<s.size()<<endl<<s<<endl;
}
