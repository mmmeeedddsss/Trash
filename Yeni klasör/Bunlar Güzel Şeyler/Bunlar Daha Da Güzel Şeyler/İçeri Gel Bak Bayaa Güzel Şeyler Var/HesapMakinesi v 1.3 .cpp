#include<iostream>
#include<cstring>
#include<conio.h>
const int MAX = 75;
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
		bool moddan_mi;
		bool is_first;
	public:
		HesapMakinesi(char *x)
		{	
			is_first=true;
			n=strlen(x);
			str=x;
			moddan_mi=false;
			Prepare();
		}
		HesapMakinesi()
		{
            is_first=true;
            moddan_mi=false;   
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
	    long long int s[MAX/2];
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
		long long int temp=0;
		i--;
		while(i>=0)
		{
			temp+=s[i--];
			temp*=10;
		}
		//cout<<temp/10<<endl;
		S.push(temp/10);
	}

	void HesapMakinesi::Calculate(int x,char m,int y)
	{
        //cout << x << m << y <<endl;
		switch(m)
		{
			case '+': S.push(x+y); break;
			case '-': S.push(x-y); break;
			case '*': S.push(x*y); break;
			case '%': S.push(x%y); break;
			case '/': if(y) S.push(x/y); else{ cout<<x<<"/"<<y<<"=inf"<<endl<<"Exiting ....."; getch(); exit(1); } break;
			default: cout<<" Unknown Opr.. "<<m; getch(); exit(1);
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
			if(chr>='0'&&chr<='9')
               {
                    S.push(chr-'0');
                    Parse();
               }
               /*
               else if(chr='m'&&str[i+1]=='o'&&str[i+2]=='d'&&str[i+3]=='(')
               {
                    int sag=0,sol=1,j=0;
                    char asd[n];
                    char temp;
                    i+=4;
                        while(sag!=0)
                        {
                        asd[j++]=str[i++];
                        if(asd[j-1]=='(') sag++;
                        if(asd[j-1]==')') sag--;
                        if(i>n) break;
                        if(j>n) break;
                        }
                        asd[j]='\0';
                 //   cout<<asd<<endl;
                    HesapMakinesi Mod_HesapliyorxD(asd);
                    S.push(Mod_HesapliyorxD.Print());
               }
               */
			else if(chr=='(')
			{     
                    if(S.gettop()!=0)
                    {
                                   int is=S.pop();
                                             if(is!='+'&&is!='-'&&is!='*'&&is!='/'&&is!='%'&&is!='(')
                                             {
                                                  if(S.gettop()>1)
                                                  { 
                                                      lastch=S.pop();
                                                      if(lastch=='%')
                                                      {
                                                            Calculate(S.pop(),lastch,is);
                                                            S.push('*');
                                                      }
                                                      else
                                                      {
                                                            S.push(lastch);
                                                            S.push(is);
                                                            S.push('*');
                                                      }
                                                  }
                                                  else
                                                  {
                                                      S.push(is);
                                                      S.push('*');
                                                  }
                                             }
                                             else
                                             { 
                                                  S.push(is);
                                             }
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
            }
            
			if(chr=='+'||chr=='-'||chr=='/'||chr=='*'||chr=='%')
			{
				if(is_first==true)
				{
					is_first=false;
					S.push(chr);
					continue;
				}
				tekrar:
				lastnum=S.pop();
				lastch=S.pop();
				if(lastch=='%')
				{
                         moddan_mi=true;
                        Calculate(S.pop(),lastch,lastnum);
                        if(S.gettop()>1) goto tekrar;
                        else goto bzt;
                    }
				if(chr=='%'||((chr=='*'||chr=='/')&&(lastch=='+'||lastch=='-')))
				{
					S.push(lastch);
					S.push(lastnum);
					S.push(chr);
					continue;
                    }
				else
				{
					Calculate(S.pop(),lastch,lastnum);
					S.push(chr);
					continue;
				}
				if(moddan_mi==true)
				{
                         bzt:
                         moddan_mi=false;
                         S.push(chr);   
                    }
			}
		}
		Solve();
	}
	void HesapMakinesi::Solve()
	{
        //Parse();
		int lastnum;
		char lastch;
		while(S.gettop()>1)
		{
			lastnum=S.pop();
			lastch=S.pop();
			Calculate(S.pop(),lastch,lastnum);
		}
	}

int main()
{
    char try_again;
    char *str;
    do{
	   str=new char[MAX+1];
	   cin>>str;
	   HesapMakinesi *s;
	   s= new HesapMakinesi(str);
	   cout<<s->Print()<<endl<<endl;
	   delete s;
	   delete str;
	   cout<<"Do You Want to Try Again?? "<<endl;
	   cin.ignore();
	   cin>>try_again;
	   system("cls");
	}while(try_again=='y'||try_again=='Y'||try_again=='e');
}
