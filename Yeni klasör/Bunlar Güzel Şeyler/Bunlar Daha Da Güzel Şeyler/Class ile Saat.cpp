#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

using namespace std;

class Time
{
      private:
              unsigned int hour;
              unsigned int minute;
              unsigned int second;
              //bool greater_than_12;
      public:
             Time()
             { hour=12; minute=0; second=0;  /* greater_than_12=false; */ }
             void settime()
             {
             cout << "Hour -->"; cin >> hour;
             if(hour>24) hour=12;
             cout << "Min. -->"; cin >> minute;
             if(minute>59) minute=59;
             cout << "Sec. -->"; cin >> second;
             if(second>59) second=59;
             }
             void changetype(char x);
             
             void display()
             {
                      cout << "\n\n\n\n\n\t\t\t      --> " << hour <<":"; printf("%02d:",minute); printf("%02d",second);
                      /* if(greater_than_12==true) cout <<" pm";
                      else cout <<" am"; */
                      cout << " <--"<<endl;
             }
             void next_second()
             {
                  second++;
                  if(second>59) { second=0; minute++; }
                  if(minute>59) { minute=0; hour++; }
             }
};


             /*void Time::changetype(char x)
             {
               if(x=='u') // usa
               {
                         if(hour>12)
                         {
                             hour-=12;
                             greater_than_12=true;
                         }
                         else
                         {
                         greater_than_12=false;
                         }
               }
               if(x=='e')  // eur
               {
                         if(greater_than_12==true)
                         {
                                            hour+=12;                           
                         }
               }
             }
             */
             
int main()
{
    Time x;
    char a;
    x.settime();
         while(1)
         {
                 Sleep(1000);
                 x.next_second();
                 system("cls");
                 x.display();
         }
    getch();
}
