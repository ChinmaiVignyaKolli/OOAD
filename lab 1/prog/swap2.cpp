//using 3rd variable
#include<iostream>
using namespace std;

void swapinteger(int a,int b)
{ 
int t;
cout<<"enter any two elemets\n";
cin>>a>>b;
t=a;
a=b;
b=t;
cout<<a<<b;
}

void swapfloating(float a,float b)
{
int t;
cout<<"enter any two elemets\n";
cin>>a>>b;
t=a;
a=b;
b=t;
cout<<a<<b;
}

void swapcharacter(char c,char d)
{
 int a,b,t;
 cout<<"enter any two elemets\n";
 cin>>c>>d;
 a=(int)c;
 b=(int)d;
 t=a;
 a=b;
 b=t;
   cout<<(char)a<<(char)b;
}
int main(void)
  {
    int ch,p,q,r,s,z,u;
  cout<<"enter option 1.to swap integers 2.swap floating nos 3.characters\n";
  cin>>ch;
  
  switch(ch)
    {
       case 1:swapinteger( p,q);
              
              break;
              
       case 2:swapfloating(r,s);
               break;
               
       case 3:swapcharacter(z,u);
                break;
                
    default:cout<<"invalid no\n";
    }
    return(0);
   }   
             

