//heapsort
#include<iostream>
#include<conio.h>
using namespace std;
void HeapSort(int a[], int n)
{
	if(n==0)
		return;
		
	int i=n,temp,flag=0;
	while(i>0)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		i--;
		n--;
		
		while(i>1)
		{
			if(a[i]>a[i/2])
			{
				temp=a[i];
				a[i]=a[i/2];
				a[i/2]=temp;				
			}
			i--;
		}
		i=n;
	}
	
}
void insert(int n, int a[], int c)
{
	if(c==1)
	{
		a[1]=n;
		return;
	}
	
	while(c>1 && a[c/2]<n)
	{
		a[c]=a[c/2];
		c=c/2;	
	}
	a[c]=n;
	
}
int main(void)
{
	
	int i=0,n,count=0,num,j=0;
	cout<<"\n Enter the number of elements: ";
	cin>>n;
	int a[n+1];
	i=0;

	while(i<n)
	{
		cout<<" Enter integer: ";
	    cin>>num;
		count++;
		insert(num,a,count);
		i++;
	}
	
cout<<"heap";
	for(j=1;j<=n;j++)
	cout<<a[j];

	HeapSort(a,n);
	cout<<"\n Sorted List: ";
	for(j=1;j<=n;j++)
		cout<<a[j];
		cout<<"max elem is"<<a[j-1];
	
}

