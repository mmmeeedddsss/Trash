/*
PROG:milk2
LANG:C++
NAME:mmmeeed1
*/
#include<iostream>
#include <fstream>
using namespace std;

struct item{
     int time;
     char event;   
};

struct item *events;

void sort(int n)
{
     int flag;
     for( int i=0; i<n; i++ )
     {
          flag = 0;
          for( int j=0; j<n; j++ )
          {
               if( events[i].time < events[j].time )
               {
                    int tempi = events[i].time;
                    char tempe = events[i].event;
                    events[i].time = events[j].time;
                    events[i].event = events[j].event;
                    events[j].time = tempi;
                    events[j].event = tempe;
                    flag = 1;
               }    
          }
          if( flag == 0 )
               return;
     }
}

int calcidle(int n)
{
     int state = 0;
     int max = 0;
     for( int i=0; i<n-1; i++ )
     {
          if( events[i].event == 's' )
               state++;
          else
               state--;
          if( state == 0 )
          {
               int idletime = events[i+1].time - events[i].time;
               if( idletime > max )
                    max = idletime;
          }
     }
     return max;
}

int calccont(int n)
{
     int state = 0;
     int max = 0;
     int starttime;
     for( int i=0; i<n; i++ )
     {
          if( state == 0 )
               starttime = events[i].time;
          if( events[i].event == 's' )
               state++;
          else
               state--;
          if( state == 0 )
          {
               int contmilking = events[i].time - starttime;
               if( contmilking > max )
                    max = contmilking;
          }
     }
     return max;
}

int main()
{
     int n;
     ofstream fout ("milk2.out");
     ifstream fin ("milk2.in");
     fin>>n;
     events = new item[n*2];
     for( int i=0; i<n*2; i++ )
     {
          fin>>events[i].time;
          events[i].event = 's';
          fin>>events[++i].time;
          events[i].event = 'f';
     }
     if( n == 1 )
     {
          fout<<events[1].time - events[0].time<<" "<<0<<endl;
          return 0;
     }
     sort(n*2);
     int idle = calcidle(n*2);
     int contmilking = calccont(n*2);
     fout<<contmilking<<" "<<idle<<endl;
     return 0;
}
