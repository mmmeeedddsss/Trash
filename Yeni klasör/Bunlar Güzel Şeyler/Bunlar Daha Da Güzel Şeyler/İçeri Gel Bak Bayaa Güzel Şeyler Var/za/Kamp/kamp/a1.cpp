#include<iostream>
#include<fstream>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

char* getDay( int g, int a )
{
    //1,1 -> thursday
    int sum = 6;
    for( int i=0; i<a; i++ )
        sum += months[i];
    sum += g;
    return days[sum%7];  
}

int main()
{
    ofstream out("");
    ifstream in("");
    int g,a;
    cin>>g>>a;
    cout<<getDay(g,a)<<endl;
}
