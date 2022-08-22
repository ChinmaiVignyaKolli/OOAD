//fixing max elem then comparing and printing max element
#include<iostream>
using namespace std;
int main(void)
{
  int i,n,MAX;
  float a[20];
  
    cout<<"enter array size\n";
    cin>>n;
    for(i=0;i<n;i++)
    {  
    cout<<"enter array element\n";
    cin>>a[i];
    
   }
   for(i=1;i<n;i++)
   {
   if(a[0]<a[i])
   a[0]=a[i];
   }
   
  cout<<"largest element is\n";
  cout<<a[0];
  
   return(0);
   }
    

