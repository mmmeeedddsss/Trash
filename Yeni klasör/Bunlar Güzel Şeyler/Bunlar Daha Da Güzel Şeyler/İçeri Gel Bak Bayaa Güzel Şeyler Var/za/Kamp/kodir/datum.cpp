#include <iostream>
#include <fstream>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int addMonth(int m, int d)
{
    int n = 0;
    for(int i=1;i<m;i++)
        n+=months[i-1];
    n+=d+2;
    n%=7;
    return n;
}

int main()
{
    ifstream inp("datum.gir");
    ofstream oup("datum.cik");
    int d,m;
    inp >> d >> m;
    oup << days[addMonth(m,d)] << endl;
    return 0;
}
