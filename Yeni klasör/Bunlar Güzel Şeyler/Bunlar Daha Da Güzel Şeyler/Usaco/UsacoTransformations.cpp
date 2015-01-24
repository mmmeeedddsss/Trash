#include<iostream>
#include<conio.h>
using namespace std;
/*
  #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
  #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
  #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
  #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
  #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
  #6: No Change: The original pattern was not changed.
  #7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
*/
char **temp;
char **first,**after;
void initTemp(int n)
{
	temp = new char*[n];
	for( int i=0; i<n; i++ )
	{
		temp[i] = new char[n];
		for( int j=0; j<n; j++ )
		{
			temp[i][j] = first[i][j];
		}
	}	
}

void rotate90(int n)
{
  
	char **temp2 = new char*[n];
	for( int i=0; i<n; i++ )
	{
		temp2[i] = new char[n];
		for( int j=0; j<n; j++ )
		{
			temp2[i][j] = temp[i][j];
		}
	}	
	
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			temp[n-1-j][i] = temp2[i][j];
	
}

bool equals(int n)
{
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			if( temp[i][j] != after[i][j] )
				return false;
	return true;
}

bool reflect(int n)
{
 
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ )
			if( i < (n-i-1) )
			{
				int tempint = temp[j][i];
				temp[j][i] = temp[j][n-1-i];
				temp[j][n-i-1] = tempint;
			}
			else
			    break;
 		
}




int doYourJob( int n )
{
	initTemp(n);
	if( equals(n) )
		return 6;
	rotate90(n); // 90
	if( equals(n) )
		return 3;
	rotate90(n); // 180
	if( equals(n) )
		return 2;
	rotate90(n); // 270
	if( equals(n) )
		return 1;
	rotate90(n); // 0
	reflect(n);
	if( equals(n) )
		return 4;
	for(int i=0; i<3; i++)
	{
		rotate90(n);
		if( equals(n) )
			return 5;
	}
	return 7;
}


int main(  )
{
	int n = 3;
	cin>>n;
	first = new char*[n];
	for( int i=0; i<n; i++ )
	{
		first[i] = new char[n];
		for( int j=0; j<n; j++ )
		{
			cin>>first[i][j];
		}
	}	
	
	after = new char*[n];
	for( int i=0; i<n; i++ )
	{
		after[i] = new char[n];
		for( int j=0; j<n; j++ )
		{
			cin>>after[i][j];
		}
	}	
	
	cout<<doYourJob( n );
	getch();
}
