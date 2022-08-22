// using arithmetic oprtns
#include<iostream>
using namespace std;

void swapinteger(int a,int b)
{
cout<<"enter any two elemets\n";
cin>>a>>b;
a=a*b;
b=a/b;
a=a/b;
cout<<a<<b;
}

void swapfloating(float a,float b)
{
cout<<"enter any two elemets\n";
cin>>a>>b;
a=a*b;
b=a/b;
a=a/b;
cout<<a<<b;
}

void swapcharacter(char c,char d)
{ int a,b;
cin>>c>>d;
a=(int)c;
b=(int)d;
a=a*b;
b=a/b;
a=a/b;
cout<<(char)a<<(char)b;
}
int main(void)
  {
    int ch,p,q,r,s,t,u;
  cout<<"enter option 1.to swap integers 2.swap floating nos 3.characters\n";
  cin>>ch;
  
  switch(ch)
    {
       case 1:swapinteger( p,q);
              
              break;
              
       case 2:swapfloating(r,s);
               break;
               
       case 3:swapcharacter(t,u);
                break;
                
    default:cout<<"invalid no\n";
    }
    return(0);
   }   
             

