#include<iostream>
#include<cstring>
#include<conio.h>
const int MAX = 50;
using namespace std;

class Stack
{
	public:
		int top;
		int values[MAX];
		~Stack()
		{
               delete values;    
          }
		Stack()
		{
			top=0;
		}
		void push(int x)
		{
			values[top++]=x;
		}
		int pop()
		{	
			if(top>0)
			return values[--top];
		}
		int gettop()
		{
			return top;
		}
		int look()
		{
            int i=top;
			while(i>=0)
			 cout<<(char)values[i--]<<"  ";
			cout<<endl;
		}
};

class HesapMakinesi
{
	private:
		Stack S;
		char *str;
		int n;
		bool is_first;
	public:
		HesapMakinesi(char *x)
		{	
			is_first=true;
			n=strlen(x);
			str=x;
			//cout<<endl<<x<<endl<<strlen(x);
			Prepare();
		}
		~HesapMakinesi()
		{
               delete str;
               S.~Stack();
          }
		void Prepare();
		void Solve();
		void Calculate(int x,char m,int y);
		void Parse();
		int Print()
		{
			return S.pop();
		}
};

	void HesapMakinesi::Parse()
	{
		char s[MAX/2];
		int i;
		for(i=0;S.gettop()!=0;)
		{
			s[i++]=S.pop();
			if(s[i-1]=='%'||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/')
			{
				S.push(s[--i]);
				if(i==0)
				    return;
				break;
			}
		}
		int temp=0;
		i--;
		while(i>=0)
		{
			temp+=s[i--];
			temp*=10;
		}
		S.push(temp/10);
	}

	void HesapMakinesi::Calculate(int x,char m,int y)
	{
        //cout<< x<< m<< y;
		switch(m)
		{
			case '+': S.push(x+y); break;
			case '-': S.push(x-y); break;
			case '*': S.push(x*y); break;
			case '%': S.push(x%y); break;
			case '/': S.push(x/y); break;
			default: cout<<" Unknown Opr.."<<m; getch(); exit(1);
		}
	}
	void HesapMakinesi::Prepare()
	{
		char chr;
		int lastnum;
		char lastch;
		for(int i=0;i<n;i++)
		{
			chr=str[i];
			//cout<<chr;
			if(chr>='0'&&chr<='9')
               {
                    S.push(chr-'0');
                    Parse();
               }
			else if(chr=='(')
			{     
                    if(S.gettop()!=0)
                    {
                                             int is=S.pop();
                                             if(is!='+'&&is!='-'&&is!='*'&&is!='/'&&is!='%'&&is!='(')
                                             {
                                                      S.push(is);
                                                      S.push('*');
                                             }
                                             else S.push((char)is);
                    }
                int sag=1;
                int j=0,u=i+1;
                char m[MAX];
                    while(1)
                    {
                        m[j++]=str[u++];
                        if(m[j-1]=='(') sag++;
                        if(m[j-1]==')') sag--;
                        i++;
                        if(sag==0) break;
                        if(u>n) break; 
                    }
                    j--;
                m[j]='\0';
                HesapMakinesi T(m);
                S.push(T.Print());
                Parse();
            }
            
			else
			{
                    bool moddan_mi=false;
                    tekrar:
				if(is_first==true)
				{
					is_first=false;
					S.push(chr);
					continue;
				}
				Parse();
				lastnum=S.pop();
				lastch=S.pop();
				if(lastch=='%')
				{
                         
                             Calculate(S.pop(),lastch,lastnum);
                             moddan_mi=true;
                             goto tekrar;
                    }
                    
                    // 5 *  
                    //
                    
				if(chr=='%'||((chr=='*'||chr=='/')&&(lastnum=='+'||lastnum=='-')))
				{
					S.push(lastch);
					S.push(lastnum);
					S.push(chr);
					continue;
				}
				else
				{
                    Parse();
					Calculate(S.pop(),lastch,lastnum);
					S.push(chr);
					continue;
				}
				if(moddan_mi==true)
                    {
                         moddan_mi=false;
                         S.push(chr);
                    }
			}
		}
		Solve();
	}
	void HesapMakinesi::Solve()
	{
		int lastnum;
		char lastch;
		while(S.gettop()>1)
		{
            Parse();
			lastnum=S.pop();
			lastch=S.pop();
			Parse();
			Calculate(S.pop(),lastch,lastnum);
		}
	}

int main()
{
	char *str;
	short i;
	char try_again;
	str=new char[MAX+1];
	do{
	cin>>str;
	HesapMakinesi s(str);
	cout<<s.Print()<<endl<<endl;
	s.~HesapMakinesi();
	cout<<"Do You Want to Try Again?? "<<endl;
	cin.ignore();
	cin>>try_again;
	system("cls");
	}while(try_again=='y'||try_again=='Y'||try_again=='e');
}
