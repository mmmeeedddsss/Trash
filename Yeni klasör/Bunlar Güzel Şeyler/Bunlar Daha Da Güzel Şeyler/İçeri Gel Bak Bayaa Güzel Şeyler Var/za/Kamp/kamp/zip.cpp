#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream out("jumps.cik");
	ifstream in("jumps.gir");
	unsigned long long int n;
	in>>n;
	unsigned long long int b,i,u;
	b = (n-3);
	i = (n-2)/2;
	u = (n-3)/3;
	unsigned long long int sum = 1;
	sum += b;
	sum %= 1000000;
	sum += i;
	sum %= 1000000;
	sum += u;
	sum %= 1000000;
	out<<sum;
	out.close();
}
