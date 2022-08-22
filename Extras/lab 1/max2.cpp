#include<iostream>
using namespace std;
const int size=50;
class array
{  
   private:
    int *a,n;
    
  public:
     array();
     void getarray();
     void showarray();
     void bubble();
  };
  
  array::array()
  {
      cout<<"enter size of array(<=50)\n";
      cin>>n;
      a=new int[n];
  }
  
  void array::getarray()
  {
     cout<<"input"<<n<<"array elements\n";
     for(int i=0;i<n;i++)
     cin>>a[i];
  };
  
  void array::showarray()
  {
     cout<<"array is\n";
     for(int i=0;i<n;i++)
     cout<<a[i];
  };
  
  void array::bubble()
  {
      int t;
      for(int i=0;i<n;i++)
           for(int j=0;j<n-1;j++)
           {
            if(a[j]>a[j+1])
               {
                 t=a[j];
                 a[j]=a[j+1];
                 a[j+1]=t;
                 }
                 
            }
    cout<<"max elem is\n"<<a[n-1];
    }
    
    int main(void)
    {
      array aa;
      aa.getarray();
      aa.showarray();
      aa.bubble();
      cout<<"after sorting\n";
      aa.showarray();
    }
                 
                 
  
  
     
 
      
      
 
     
     
