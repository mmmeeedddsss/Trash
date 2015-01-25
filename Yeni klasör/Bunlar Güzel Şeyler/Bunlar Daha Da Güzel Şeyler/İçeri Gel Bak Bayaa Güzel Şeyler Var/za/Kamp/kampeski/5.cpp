#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("ccc.gir");
	ofstream out("ccc.cik");
	string s;
	in>>s;     
	out<<s;
	out.close();
}
