#include<iostream>
#include<conio.h>
using namespace std;
class GCD
 { 
 public:
	int gcd(int,int);
 };

int GCD::gcd(int a,int b)
  {
	if(a%b==0)
		return(b);
	else
		return(gcd(b,a%b));
  }

int main (void)
{
  GCD g;
  int a,b,ans;
  cout<<"input two nos";
  cin>>a>>b;
  ans=g.gcd(a,b);
  cout<<"gcd of given nos is";
  cout<<ans;
}
