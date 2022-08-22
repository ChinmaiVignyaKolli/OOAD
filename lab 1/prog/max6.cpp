//finding the  pair with max product  and printing the largest element from the pair
#include<iostream>
using namespace std;
void maxProduct(int arr[], int n)
{    
    int a = arr[0];
	int b = arr[1];
 
    for (int i=0; i<n; i++)
      for (int j=i+1; j<n; j++)
         if (arr[i]*arr[j] > a*b)
            a = arr[i], b = arr[j];
 
        cout << "Max product pair is {" << a << ", "
         << b << "}";
         if(a>b)
         cout<<"max element is"<<a;
         else
         cout<<"max element is"<<b;
    if (n < 2)
    {
        cout << "No pairs present \n";
        return;
    }
 
}
 
 int main(void)
  { 
    int n;
    int arr[n] ;
    int i;
    printf("enter the size of the array");
    scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
    maxProduct(arr, n);
    return 0;
  }

