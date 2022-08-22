#include<iostream>
#include<stdlib.h>
#define MAX 250
using namespace std;

int adj[MAX][MAX],n,m_frd[MAX],flag=-1;

int check(int a,int d[],int k)
{
  flag=0;
  for(int i=1;i<=k;i++)
    if(d[i]==a)
    {
      flag=1;
      break;
    }
  return flag;
}

int connect(int r,int ele)
{
  m_frd[++r]=ele;
  //cout<<" Element added:"<<ele<<"( "<<r<<")";
  for(int i=1;i<=n;i++)
  {
    if(!check(i,m_frd,r))
    {
     //cout<<endl<<i;
     flag=0;
     for(int j=1;j<=r;j++)
     {
       if(adj[i][(m_frd[j])]==0)
         flag=1;
     }
     if(flag==0)
     {
       //cout<<"Flag is 0";
       r=connect(r,i);
     }
    }
   }
  if(flag==1)
  {
    //cout<<"\nCount:"<<r;
    return r;   
  } 
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
 res=(a*a*a);
 return(res/6);
}

int subset()
{
  int z=0,i,j,k,f=0;
  int size=(Comb(n));
  int Count[size];
  //cout<<"Comb("<<n<<",3) is:"<<size;
  //cout<<"\nInside Subset";
  for(i=1;i<=n;i++)
  {
    //cout<<endl<<"Inside i:";
    for(j=i+1;j<=n;j++)
    {
      //cout<<endl<<"Inside j:";
      for(k=j+1;k<=n;k++)
      {
        //cout<<endl<<"Inside k:";
        m_frd[1]=i;
        m_frd[2]=j;
        //cout<<" "<<i<<" "<<j;
        if(adj[i][j]==1 && adj[j][k]==1 && adj[i][k]==1)
        {
          //cout<<"\nInside Mutual Friends"; 
          //cout<<" "<<i<<" "<<j<<" "<<k;
          Count[++z]=connect(2,k);
          //cout<<"\nOutside Mutual Friends";
          f=1; 
        }
      }
    }
  } 
  if(f==0)
  {
    for(i=1;i<=n;i++)
    {
      //cout<<endl<<"Inside i:";
      for(j=i+1;j<=n;j++)
        if(adj[i][j]==1)
          Count[++z]=2;  
    }
  }
  return(max(Count,z));
}

int main()
{
 int i=1,j;
 //cout<<"\nEnter the number of people:";
 //cin>>n;
 srand(time(NULL));
 n=rand()%15;
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     adj[i][j]=0;
 /*while(i)
 {
   int a,b;
   //cout<<"\nEnter the people who are friends:";
   do
   {
     a=rand()%(n+1);
     b=rand()%(n+1);
   }while(a==b || a==0 || b==0);
   adj[a][b]=1;
   adj[b][a]=1;
   //cout<<"\nEnter 1 to continue:\t";
   //cin>>i;
 }*/
 for(i=1;i<=n;i++)
 {  
   for(j=i+1;j<=n;j++)
     if(i!=j)
     {
       adj[i][j]=rand()%2;
       adj[j][i]=adj[i][j];
     }
 }
 cout<<"\nAdjacency matrix:\n";
 for(i=1;i<=n;i++)
 {  
   for(j=1;j<=n;j++)
     cout<<" "<<adj[i][j];
   cout<<endl;
 }
  for(i=1;i<=n;i++)
 {  
   for(j=1;j<=n;j++)
   {
     if(adj[i][j]==1)
      cout<<" ("<<i<<","<<j<<") ";
   }
   cout<<endl;
 }
 if(n==0)
  cout<<"There is no community\n";
 else if(subset()>1 && subset()<=n)
  cout<<"Max Community Size Possible is:"<<subset()<<endl;
 else
  cout<<"Max Community Size Possible is:1\n";
 return 0;
}
