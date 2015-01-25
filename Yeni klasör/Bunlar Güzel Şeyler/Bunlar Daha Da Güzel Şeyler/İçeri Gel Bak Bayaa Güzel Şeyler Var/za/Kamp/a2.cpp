#include<iostream>
#include<fstream>
using namespace std;

int a[5];

int sort()
{
    ofstream out("Mjehuric.cik");
    bool flag;
    do
    {
        flag = false;
        for( int i=0; i<4; i++ )
        {
            if( a[i] > a[i+1] )
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                for( int i=0; i<5; i++ )
                    out<<a[i]<<" ";
                out<<endl;
                flag = true;
            }
        }
    }while( flag );
}

int main()
{
    ifstream in("Mjehuric.gir");  
    for(int i=0;i<5;i++)
        in >> a[i];
    sort();
    return 0;
}
