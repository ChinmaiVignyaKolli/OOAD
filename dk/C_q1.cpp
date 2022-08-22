#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAX 50
using namespace std;

int s[MAX];
int adj[50][50],deg[50],reach[50],police[50];
int top=-1;
int n;

void fn(int v)
{
  if(reach[v]==1)
    return;
  else if(deg[v]>=1)
    {
      for(int i=1;i<=n;i++)
      {
        if((adj[v][i]==1)&&reach[i]==1&&police[i]==0)
        {
          cout<<endl<<"At Junc "<<v<<" Police is assigned"<<endl;
          police[v]=1;
        }
      }
    }
}

void dfs(int v)
{
 int i;
 reach[v]=1;
 for(i=1;i<=n;i++)
  {
   if(adj[v][i] && !reach[i] )
   {
    cout<<v<<"->"<<i<<endl;
    fn(i);
    dfs(i);
   }
  }
}

int main()
{
 int i=1;
 cout<<"\nEnter the number of vertices:";
 cin>>n;
 for(i=1;i<=n;i++)
  reach[i]=0;
 while(i){
 int a,b;
 cout<<"\nEnter the vertices to connect:";
 cin>>a>>b;
 adj[a][b]=1;
 adj[b][a]=1;
 cout<<"\nEnter 1 to continue:\t";
 cin>>i;
 }
 int j;
 for(i=1;i<=n;i++){
  for(j=1;j<=n;j++)
    cout<<adj[i][j];
  cout<<endl;
 }
 for(int i=1;i<=n;i++)
 {
  deg[i]=0;
  police[i]=0;
 }
 for(int i=1;i<=n;i++)
 {
   for(int j=1;j<=n;j++)
   {
    if(adj[i][j]==1)
    {
      (deg[i])++;
    }
   }
 }
 cout<<endl;
 int v=1;
 if(v==1)
 {
   //visited[v]=1;
   if(deg[v]==1)
   {
     dfs(v);
   }
   else
   {
     cout<<endl<<"At Junc "<<v<<" Police is assigned"<<endl;
     police[v]=1;
     dfs(v);
   }
 }
 int count=0;
 //cout<<endl<<"Police:";
 for(i=1;i<=n;i++)
 {
   if(police[i]==1)
     count++;
 }
 cout<<"\nNumber of policemen:"<<count<<endl;
 return 0;
}
