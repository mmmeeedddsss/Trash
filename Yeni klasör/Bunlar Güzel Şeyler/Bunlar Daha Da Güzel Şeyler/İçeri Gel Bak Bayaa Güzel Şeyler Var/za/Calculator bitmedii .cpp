#include<iostream>
#include<cstring>
#include<conio.h>
#define MAX 75

using namespace std;

 struct Node{
     int value;
     struct Node *next,*prev;     
     };
     
 class Calculator{
     public:
          Node *Head;
          int result;
          //
          //    ------------------------------->
          // 
          Calculator(char *x)
          {
               Node *prevn = new Node;
               Head = prevn;
               prevn -> value = x[0];
               prevn -> prev = NULL;
               for(int i=1 ; x[i] != 'b' ; i++)
               {
                    Node *newn = new Node;
                    newn -> value = x[i];
                    newn -> next = NULL;
                    newn -> prev = prevn;
                    prevn -> next = newn;
                    prevn = newn;
               }
          }
          //
          //    ------------------------------->
          // 
          void Solve()
          {    
               Sayi_Kontrol();
               Negatif_Kontrol();
               //Parantez_Kontrol();
               Us_Kontrol();
               //Mutlak_Kontrol();
               Normal_Islem_Kontrol();
               result = Cevap_Uret();
          }
          
          int Cevap_Uret()
          {
               return Head -> value;    
          }
          
          void Sayi_Kontrol()
          {
               Node *iterator = Head -> next ;
               iterator -> prev -> value -= '0';
               while( iterator -> next != NULL )
               {
                    if( iterator -> value >= '0' && iterator -> value <= '9' )
                    {
                         iterator -> value -= '0';
                         if( 
                         iterator -> prev -> value != '*' &&
                         iterator -> prev -> value != '/' &&
                         iterator -> prev -> value != '+' &&
                         iterator -> prev -> value  != '-' &&
                         iterator -> prev -> value  != '%' &&
                         iterator -> prev -> value  != '<' &&
                         iterator -> prev -> value  != '>' &&
                         iterator -> prev -> value  != '(' &&
                         iterator -> prev -> value  != ')' &&
                         iterator -> prev -> value  != '^' &&
                         iterator -> prev -> value  != 'n' ) 
                         {
                              iterator -> prev -> value = iterator -> prev -> value * 10 + iterator -> value;
                              iterator -> prev -> next = iterator -> next;
                              iterator -> next -> prev = iterator -> prev;    
                         }
                    }
                    iterator = iterator -> next;
               }
               iterator -> value -= '0';
               if( 
                         iterator -> prev -> value  != '*' &&
                         iterator -> prev -> value  != '/' &&
                         iterator -> prev -> value  != '+' &&
                         iterator -> prev -> value  != '-' &&
                         iterator -> prev -> value  != '%' &&
                         iterator -> prev -> value  != '<' &&
                         iterator -> prev -> value  != '>' &&
                         iterator -> prev -> value  != '(' &&
                         iterator -> prev -> value  != ')' &&
                         iterator -> prev -> value  != '^' &&
                         iterator -> prev -> value  != 'n' ) 
                         {
                              iterator -> prev -> value = iterator -> prev -> value * 10 + iterator -> value;
                              iterator -> prev -> next = NULL;  
                         }  
          }
          
          void Negatif_Kontrol()
          {
               Node *iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == 'n' )
                    {
                         iterator -> next -> value = -(iterator -> next -> value);
                         iterator -> prev -> next = iterator -> next;
                         iterator -> next -> prev = iterator -> prev;
                    }
                    iterator = iterator -> next;
               }    
          }
          
          void Parantez_Kontrol()
          {
               Node *iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '(' )
                    {
                         Node *Found_location = iterator;
                         char *x = new char[MAX+1];
                         int i=0,sayac=0;
                         iterator = iterator -> next;
                         while( iterator -> value != ')' || sayac != 0 )
                         {
                              if(iterator -> value == '(' ) sayac++;
                              else if( iterator -> value == ')' ) sayac--;
                              
                              x[i++] = iterator -> value;
                              
                              if ( iterator -> next != NULL )
                                   iterator = iterator -> next;
                              else
                              {
                                   cout<<"Bad Input :(\n";
                                   getch();
                                   exit(1);
                              }
                         }
                         x[i] = '\n';
                         x[i+1] = '\0';
                         
                         Node *Last = iterator -> next;
                         
                         Calculator cal(x);
                         cal.Solve();
                         int res = cal.result;
                         
                         Node *newn = new Node;
                         newn -> value = res;
                         Found_location -> next = newn;
                         newn -> next = Last;
                         newn -> prev = Found_location;
                         Last -> prev = newn;
                    }
                    iterator = iterator -> next;
               }
          }
          void Us_Kontrol()
          {
               Node *iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '^' )
                    {
                         iterator -> value = pow( iterator -> prev -> value , iterator -> next -> value );
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else{
                              iterator -> next = NULL;
                              break;
                         }
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                    }
                    iterator = iterator -> next;
               }
          }
          
          int pow( int x ,int y )
          {
               int sonuc=1;
               for(int i=0;i<y;i++)
               {
                    sonuc*=x;    
               }    
               return sonuc;
          }
          
          void Mutlak_Kontrol()
          {
               Node *iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '<' )
                    {
                         Node *Found_location = iterator;
                         char *x = new char[MAX+1];
                         int i=0,sayac=0;
                         iterator = iterator -> next;
                         while( iterator -> value != '>' || sayac != 0 )
                         {
                              if(iterator -> value == '<' ) sayac++;
                              else if( iterator -> value == '>' ) sayac--;
     
                              x[i++] = iterator -> value;
                              if ( iterator -> next != NULL )
                                   iterator = iterator -> next;
                              else
                              {
                                   cout<<"Bad Input :(\n";
                                   getch();
                                   exit(1);
                              }
                         }
                         x[i] = '\n';
                         Node *Last = iterator -> next;
                         
                         Calculator cal(x);
                         cal.Solve();
                         int res = cal.result;
                         if( res < 0 ) res = -res;
                         
                         Node *newn = new Node;
                         newn -> value = res;
                         Found_location -> next = newn;
                         newn -> next = Last;
                         newn -> prev = Found_location;
                         Last -> prev = newn;
                    }
                    iterator = iterator -> next;
               }    
          }
          void Normal_Islem_Kontrol()
          {
               Node *iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '%' )
                    {
                         iterator -> value = (iterator -> prev -> value) % (iterator -> next -> value);
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else
                         {
                              iterator -> next = NULL;
                              break;
                         }
                    } 
                    iterator = iterator -> next;
               }  
               
               iterator = Head;  
               while( iterator -> next != NULL )
               {
                    Node *temp = Head;
                    while( temp -> next != NULL )
                    {
                         cout<<temp -> value<<" ";  
                         temp = temp -> next;  
                    }
                    cout<<temp -> value<<endl<<endl;    
                    if( iterator -> value == '*' )
                    {
                         iterator -> value = (iterator -> prev -> value) * (iterator -> next -> value);
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else
                         {
                              iterator -> next = NULL;
                              break;
                         }
                    }  
                    iterator = iterator -> next;
               }
               
               iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '/' )
                    {
                         iterator -> value = (iterator -> prev -> value) / (iterator -> next -> value);
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else
                         {
                              iterator -> next = NULL;
                              break;
                         }
                    }
                    iterator = iterator -> next;  
               }    
               
               iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '+' )
                    {
                         iterator -> value = (iterator -> prev -> value) + (iterator -> next -> value );
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else
                         {
                              iterator -> next = NULL;
                              break;
                         }
                    } 
                    iterator = iterator -> next; 
               }
               
               iterator = Head;
               while( iterator -> next != NULL )
               {
                    if( iterator -> value == '-' )
                    {
                         iterator -> value = (iterator -> prev -> value) - (iterator -> next -> value);
                         if( iterator -> prev -> prev != NULL ) iterator -> prev -> prev -> next = iterator;
                         else Head = iterator;
                         if( iterator -> next -> next != NULL ) iterator -> next -> next -> prev = iterator;
                         else
                         {
                              iterator -> next = NULL;
                              break;
                         }
                    } 
                    iterator = iterator -> next; 
               }  
          }
};

int main()
{
     char tkrr = 'e';
     while( tkrr == 'e' )
     {
          system("cls");
          char *x = new char[MAX];
          cin>>x;
          Calculator c(x);
          c.Solve();
          cout<<endl<<endl<<endl<<" >"<<c.result<<endl;
          tkrr = getch();
     }
}
