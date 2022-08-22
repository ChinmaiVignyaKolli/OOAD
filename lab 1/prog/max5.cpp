//Finding Max by finding the pair of elements whose diff is least and priting the largest element from the pair
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(void)
{
	 int i=0,j=0,f=0,k,n;
	 cout<<"enter the no of inputs"<<ends;
      cin>>n;
      int a[n];
      cout<<"the nos generated are"<<endl;

         for(i=0;i<n;i++)
          {
             a[i]=rand();
             cout<<a[i]<<endl;
          }
          i=0;
       
         while((i<n)&&(f!=1))
         {
    		for(j=i+1;j<n;j++)
    		{
    			if((a[j]-a[i])>0)
    			{
    				i=j;
    				k=a[j];
    				break;
    			}
            }
           if(j==n)
             {
               f=1;
              }
           }	
    		
     cout<<"the max element is"<<k<<endl;
	
     return(0);	
   }




