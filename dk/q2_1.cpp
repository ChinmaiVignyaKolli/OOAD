#include<iostream>
#include<stdlib.h>
#define MAX 250
using namespace std;

int adj[MAX][MAX],n,m_frd[MAX],count,sub[3];

int check(int a,int d[],int k)
{
  int flag=0;
  for(int i=1;i<=k;i++)
    if(d[i]==a)
    {
      flag=1;
      break;
    }
  return flag;
}

void connect(int a,int b,int c)
{
  //cout<<endl;
  cout<<a<<","<<b<<","<<c<<" are 3 mutual friends";
  sub[0]=a;
  sub[1]=b;
  sub[2]=c;
  for(int i=1;i<=3;i++)
    m_frd[i]=sub[i-1];
  count=3;
  L:for(int i=1;i<=n;i++)
  {
    if(!check(i,m_frd,count))
    {
     for(int j=1;j<=count;j++)
     {
       if(adj[i][(m_frd[j])]==0)
         goto L;
     }
     m_frd[++count]=i;
    }
  }
  cout<<" Count:"<<count;
  //return count;
}

int max(int x[],int k)
{
  int maximum=x[1];
  for(int i=2;i<=k;i++)
    if(x[i]>maximum)
      maximum=x[i];
  return maximum;
}

int Comb(int a)
{
 int res;
 res=(a*(a-1)*(a-2));
 return(res/6);
}

int subset()
{
  int z=0;
  int size=(Comb(n));
  int Count[size];
  cout<<"Comb("<<n<<",3) is:"<<size;
  cout<<"\nInside Subset";
  for(int i=1;i<=n;i++)
  {
    cout<<endl<<"Inside i:";
    for(int j=i+1;j<=n;j++)
    {
      cout<<endl<<"Inside j:";
      for(int k=j+1;k<=n;k++)
      {
        cout<<endl<<"Inside k:";
        if(adj[i][j]==1 && adj[j][k]==1 && adj[i][k]==1)
        {
          cout<<"\nInside Mutual Friends"; 
          cout<<" "<<i<<" "<<j<<" "<<k;
          connect(i,j,k);
          //Count[++z]=c;
          cout<<"\nOutside Mutual Friends"; 
        }
      }
    }
  } 
  return(max(Count,z));
}

int main()
{
 int i=1;
 cout<<"\nEnter the number of people:";
 cin>>n;
 while(i)
 {
   int a,b;
   cout<<"\nEnter the people who are friends:";
   cin>>a>>b;
   adj[a][b]=1;
   adj[b][a]=1;
   cout<<"\nEnter 1 to continue:\t";
   cin>>i;
 }
 /*int j;
 for(i=1;i<=n;i++)
 {  
   for(j=1;j<=n;j++)
     cout<<adj[i][j];
   cout<<endl;
 }*/
 cout<<"\n Max Community Size Possible is:"<<subset();
 return 0;
}
