//using average finding max element in the array
#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{
	  int n,i=0,j=0,sum=0,f,t;
	  float avg;
	  cout<<"enter the size of the array\n"<<endl;
	  cin>>n;
	  int a[n][n];
	  
	  for(i=0;i<n;i++)
	   {
	   for(j=0;j<n;j++)
	      {
	   	a[i][j]=-1;
	      }
       }
       
       cout<<"numbers generated are\n"<<endl;
       for(i=0;i<n;i++)
       {
       	a[0][i]=rand();
       	cout<<a[0][i]<<endl;
       	
	   }
	   i=0;
	   while(a[i][j]>0)
     {
     	sum=0;
     	j=0;
     	while(a[i][j]>0)
     	   {
     	     sum=sum+a[i][j];
		      j++;
		 	}
		 	avg=sum/j;
		 	
		 	f=0;
		 	t=0;
		 	while(a[i][f]>0)
		 	{
		 		   if(f<n)
		 		   {
		 		   	if(a[i][f]>avg)
		 		   	    {
		 		   		a[i+1][t]=a[i][f];
		 		   		t++;
						}
						f++;
					}
					else
					break;
			 }
			 i++;
	}
	cout<<"max is\n"<<a[i][0];
	return(0);	 	 
}
