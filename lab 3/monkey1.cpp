#include<iostream>
#include<stdlib.h>
#define ARR_SIZE 100
using namespace std;
 class monkey
 {
 	public:
 		void print(int a[], int max_i)
        {
                 int i;
                 for (i = 0; i < max_i; i++)
                 cout << a[i];
                 cout << " " << endl;
        }

         void printcompositions(int n, int i)
         {
 
                static int a[ARR_SIZE];
 
                if (n == 0)
                {
                 print(a, i);  // the final array when sum is computed and brought down to zero and 'i' is incremented to its max.
                }
                else if(n > 0)
                {
                   int k; 
                  for (k = 1; k <= 2; k++)
                  {
                   a[i]= k;
                   printcompositions(n-k, i+1); // reducing the sum by k (considering k as 1 or 2) and incrementing i so on.
                  }
                }
         }
void count(int n)
{
	int  t1 = 1, t2 = 2, nextTerm = 0;
    for (int i = 1; i <= n; ++i)
    {    
       if(i == 1)
        {
        	nextTerm++;
            continue;
        }
        if(i == 2)
        {        
            nextTerm=nextTerm+1;
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
       cout << "count is" << nextTerm << " ";
}
};

int main(void)
{
  int n = 3;  // change the input from here.
  monkey obj,obj1;
  cout <<"monkey climbing stairs by 1 and 2 of "<< n << endl;
  obj.printcompositions(n, 0);
  obj1.count(n);
  getchar();
  return 0;
}
