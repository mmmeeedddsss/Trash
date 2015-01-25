#include<iostream>
using namespace std;

int a[5];

int sort()
{
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
                    cout<<a[i]<<" ";
                cout<<endl;
                flag = true;
            }
        }
    }while( flag );
}

int main()
{
    for(int i=0;i<5;i++)
        cin >> a[i];
    sort();
}
