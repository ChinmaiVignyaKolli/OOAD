/*GCD k integers*/

#include<iostream>
using namespace std;

class Gcd
{
	private:
		int a,b;
	
		
	public:
		int gcdf(int M, int m);
		void max(int X, int Y)
		{
			int temp;
			if(X>Y)
			{
			}
			else
			{
				temp=Y;
				Y=X;
				X=temp;
			}
			
		}

				
};
int Gcd ::gcdf(int M,int m)
{
	int p;
	if(m==0&&M!=0)
	{
		return M;
	}
	else	if(m!=0&&M==0)
			{
				return m;
			}
			
			else	if(m==0&&M==0)
					{
						p=0;
						 return (p);
					}
			
					else 
					{
						if((M%m)>0)
						{
							gcdf(m ,(M % m));		
						}
						
						else
						{
							return(m);
						}
					}
		
}

int main(void)
{
	int k,i;
	cout<<"enter the k value\n";
	cin>>k;
	int a[k],temp;
	Gcd obj;
	cout<<"Enter the numbers\n";
	
	cin>>a[0];
	for(i=0;i<k-1;i++)
	{
		cin>>a[i+1];
		obj.max(a[i],a[i+1]);
		a[i+1]=obj.gcdf(a[i],a[i+1]);
	}
	
	cout<<"GCD is :"<<a[k-1];
	
	
}
