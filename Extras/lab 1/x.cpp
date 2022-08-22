#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
char a[n][n]={'\'};
int i,j,k;
for(i=0;i<n;i++)
{
j=n-i-1;
k=n-1;
while(k>=j)
{
a[i][k]='#';
}
}

for(i=0;i<n;i++)
{cout<<"\n";
for(j=0;j<n;j++)
{
cout<<a[i][j];
}
}

return 0;
}
