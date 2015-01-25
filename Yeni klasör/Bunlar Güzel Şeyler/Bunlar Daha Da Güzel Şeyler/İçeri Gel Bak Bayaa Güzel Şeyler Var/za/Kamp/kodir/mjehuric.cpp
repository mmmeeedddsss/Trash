#include <iostream>
#include <fstream>
using namespace std;

void printV(int *V, ostream& oup)
{
    for(int i=0;i<5;i++)
        oup << V[i] << " ";
    oup << endl;
}

void bubble(int* V)
{
    ofstream oup("Mjehuric.cik");
    bool isChanged = true;
    while(isChanged)
    {
        isChanged = false;
        for(int i=0;i<4;i++)
        {
            if(V[i] > V[i+1])
            {
                swap(V[i], V[i+1]);
                printV(V, oup);
                isChanged = true;
            }
        }
    }
}

int main()
{
    ifstream inp("Mjehuric.gir");
    int V[5];
    for(int i=0;i<5;i++)
        inp >> V[i];
    bubble(V);
    return 0;
}
