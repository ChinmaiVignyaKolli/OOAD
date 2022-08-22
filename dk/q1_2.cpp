#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAX 50
using namespace std;

int q[MAX];
int adj[50][50],level[50][50],reach[50],police[50];
int front=-1;
int rear=-1;
int n,count=0;

void enqueue(int v)
{
 if(rear==MAX-1)  
  cout<<"......Queue is full";
 else
 { 
   if(front==-1)
    front=0;
   q[++rear]=v;
 }
}

int dequeue()
{
  if(front==-1 || front>rear)
    return -1;
  int t=q[front++];
  return t;
}

void bfs(int v)
{
 enqueue(v);
 reach[v]=1;
 cout<<endl<<v<<endl;
  
 int i;
 while(front!=-1 && front<=rear)
 {
  v=dequeue();
 
  reach[v]=1;
  int j=0;
  for(i=1;i<=n;i++)
  {

   if(adj[v][i]==1 && reach[i]==0)
    {
     enqueue(i);
     //count++;
     level[count][j++]=i;
     cout<<i<<" ";
     reach[i]=1;
    }
  }
  level[count][j]=-5;
  cout<<endl;
  for(i=0;i<=j;i++)
    cout<<" "<<level[count][i];
  cout<<endl;
}
}

int main()
{
 int i=1;
 cout<<"\nEnter the number of vertices:";
 cin>>n;
 for(i=1;i<=n;i++)
   reach[i]=0;
 while(i)
 {
   int a,b;
   cout<<"\nEnter the vertices to connect:";
   cin>>a>>b;
   adj[a][b]=1;
   adj[b][a]=1;
   cout<<"\nEnter 1 to continue:\t";
   cin>>i;
 }
 int j;
 for(i=1;i<=n;i++)
 {  
   for(j=1;j<=n;j++)
     cout<<adj[i][j];
   cout<<endl;
 }
 for(int i=1;i<=n;i++)
 {
   //deg[i]=0;
   police[i]=0;
 }
 /*for(int i=1;i<=n;i++)
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
 for(int i=1;i<=n;i++)
 {
  cout<<" "<<deg[i];
 }*/

 int v=1;
 if(v==1)
 {
   police[v]=1;
   level[0][0]=v;
   bfs(v);
 }
 cout<<endl<<"No. OF LEVELS: "<<count;
 for(i=0;i<=count;i++)
 {
   for(j=0;j<50;i++)
   {
     if(level[i][j]==-5)
       break;
     cout<<" "<<level[i][j];
   }
   cout<<endl;
 }
 /*int count=0;
 //cout<<endl<<"Police:";
 for(i=1;i<=n;i++)
 {
   if(police[i]==1)
     count++;
 }
 cout<<"\nNumber of policemen:"<<count<<endl;*/
 return 0;
}
