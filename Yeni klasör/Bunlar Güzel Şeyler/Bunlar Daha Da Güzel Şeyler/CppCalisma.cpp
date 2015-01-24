#include<iostream>
#include<conio.h>

using namespace std;

class Reel

{
     friend ostream& operator << (ostream& os, Reel& r)
     {
          os << r.pay << "/" << r.payda << endl;
          return os;
     }
     
     friend istream& operator >>(istream& is,Reel& d2)
     {
          is>>d2.pay>>d2.payda;
          return is;
     }

     private:
          int pay,payda;
     public:
          Reel()
          { pay=0; payda=0; }
          
          Reel(int x,int y)
          { pay=x; payda=y; }
          
          Reel& operator + (Reel d2);
          
          Reel& operator - (Reel d2);
          
          void scanf()
          { 
          int x,y;
          cout<<"Pay -->"; cin>>x;
          cout<<"Payda -->"; cin>>y;
          pay=x; payda=y; 
          }
          
          Reel& operator *(Reel d2);
          
          Reel& operator /(Reel d2);
          
          void sadelestir();
          
};
     
     Reel& Reel::operator *(Reel d2)
     {
          Reel& temp=*(new Reel());
          temp.pay=pay*d2.pay;
          temp.payda=payda*d2.payda;
          temp.sadelestir();
          return temp;
     }
     
     Reel& Reel::operator /(Reel d2)
     {
          Reel& temp=*(new Reel());
          temp.pay=pay*d2.payda;
          temp.payda=payda*d2.pay;
          
          temp.sadelestir();
          return temp;
     }

     void Reel::sadelestir()
     {
          int i;
          if(pay==payda){ pay=1; payda=1; }
          for(i=2;i<pay&&i<payda;i++)
               if(pay%i==0&&payda%i==0)
               {
                     pay/=i;
                     payda/=i;
                     i=2;
               }
     }
     
     Reel& Reel::operator + (Reel d2)
          {
               int tpay=0,tpayda=0;
               
               tpayda=d2.payda*payda;
               pay*=d2.payda;
               d2.pay*=payda;
               
               tpay= pay+d2.pay;
               
               Reel& temp=*(new Reel(tpay,tpayda));
               d2.sadelestir();
               sadelestir();
               
               temp.sadelestir();
               return temp;
          }
          
     Reel& Reel::operator - (Reel d2)
          {
               int tpay=0,tpayda=0;
               
               tpayda=d2.payda*payda;
               pay*=d2.payda;
               d2.pay*=payda;
               
               tpay= pay-d2.pay;
               
               Reel& temp=*(new Reel(tpay,tpayda));
               d2.sadelestir();
               sadelestir();
               
               temp.sadelestir();
               return temp;
          }

int main()
{
     int a=3;
     //f(a)++; 
     //arttir(5);
     Reel x,y;
     char m;
     x.scanf();
     cout<<"Islem Ne??";
     cin>>m;
     y.scanf();
          switch(m)
          {
               case'+': cout << (x+y); break;
               case'-': cout << (x-y); break;
               case'/': cout << (x/y); break;
               case'*': cout << (x*y); break;
          }
     getch();
}
