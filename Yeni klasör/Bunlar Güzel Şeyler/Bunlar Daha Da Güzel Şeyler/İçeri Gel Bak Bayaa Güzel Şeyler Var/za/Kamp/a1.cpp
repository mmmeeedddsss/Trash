#include<iostream>
#include<fstream>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

char* getDay( int g, int a )
{
    //1,1 -> thursday
    int sum = 3;
    for( int i=1; i<a; i++ )
        sum += months[i-1];
    sum += g-1;
    return days[sum%7];  
}

int main()
{
    ofstream out("datum.cik");
    ifstream in("datum.gir");
    int g,a;
    in>>g>>a;
    out<<getDay(g,a)<<endl;
}
