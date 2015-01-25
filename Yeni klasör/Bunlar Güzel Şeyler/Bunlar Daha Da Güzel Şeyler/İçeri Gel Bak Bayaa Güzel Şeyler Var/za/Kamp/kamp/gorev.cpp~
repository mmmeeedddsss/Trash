#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool asdf = false;

unsigned long long int mult(long prime, long pow1, long pow2)
{
	long min = ( (pow1>pow2)?pow2:pow1 );
	unsigned long long int pow = 1;
	for( long i=0; i<min; i++ )
	{
		pow *= prime;
		if( pow > 1000000000 ) asdf = true;
		pow%=1000000000; // yavaş
	}
	return pow;
}

vector<long> primes( long n )
{
	vector<long> v;
	v.push_back(2);
	bool flag;
	long j;
	for( long i=3; i<n; i+=2 )
	{
		flag = true;
		j = 0;
		while( v.size() > j &&v[j] * v[j] <= i  )
		{
			if( i%v[j] == 0 )
			{
				flag = false;
				break;
			}
			j++;
		}
		if( flag )
			v.push_back(i);
	}
	return v;
}

int main()
{
	freopen("zadaca.cik","w",stdout);
	ifstream in("zadaca.gir");
	const int primeCount = 100000;
	vector<long> v = primes(primeCount);
	
	int n,m;
	in>>n;
	int *a1 = new int[n];
	for( int i=0; i<n; i++ )
		in>>a1[i];
		
	in>>m;
	int *a2 = new int[m];
	for( int i=0; i<m; i++ )
		in>>a2[i];
	
	long s1=0,s2=0;
	unsigned long long int ans = 1;
	for( long k=0; k<v.size(); k++ )
	{
		s1 = s2 = 0;
		for( int i=0; i<n; i++ )
		{
			while( a1[i]%v[k] == 0 )
			{
				a1[i]/=v[k];
				s1++;
			}
		}
		
		for( int i=0; i<m; i++ )
		{
			while( a2[i]%v[k] == 0 )
			{
				a2[i]/=v[k];
				s2++;
			}
		}
		
		ans *= mult(v[k],s1,s2);
		if( ans > 1000000000000 ) asdf = true;
		ans %= 1000000000;
	}
	if( !asdf )
		printf("%lld",ans);
	else
		printf("%09lld",ans);
}
