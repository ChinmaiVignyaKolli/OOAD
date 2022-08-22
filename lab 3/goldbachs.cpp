#include<iostream>
#include<math.h>

using namespace std;

class golbach
{
	public:
		unsigned long long int l;
		unsigned long long int u;
		
		golbach(unsigned long long int n,unsigned long long int m)
		{
			u=n;
			l=m;
		}

		golbach()
		{
			u=4;
			l=100;
		}

		int isprime(unsigned long long int x);
		int isgolbach(unsigned long long int a);
};


int golbach::isprime(unsigned long long int x)
{
	int i=2,root;
	root=sqrt(x);
	if(x==2)
	{
		return(1);
	}
	else if(x==1)
		{
			return(0);
		}
		else
		{
			while(i<=root+1)
			{
				if((x%i)==0)
				{
					return(0);
				}
				else
				{
					i++;			
				}	
			}
	
		return(1);
		}	
}


int golbach::isgolbach(unsigned long long int a)
{
	unsigned long long int i;
	unsigned long long int t;
	t=a/2+1;
	for(i=1;i<t;i++)
	{
		if(isprime(i)&isprime(a-i))
		{
			cout<<a<<"="<<i<<"+"<<a-i<<endl;
			return(1);
		}	
	}
	if(i==t)
		return(0);
}

int main(void)
{
	unsigned long long int k=4;
	golbach g;

	cout<<"Enter the lower bound and upper bound up to which it is to verified"<<endl;
	cin>>g.l>>g.u;
	
	for(k=g.l;k<g.u;k=k+2)
	{
		if(g.isgolbach(k)==1)
		{
					
		}
		else
		{
			cout<<"Conjecture fails at: "<<k<<endl;
			break;
		}	
	}
	
	if(k==g.u)
	{
		cout<<"conjecture is true"<<endl;
	}

return(0);
}

