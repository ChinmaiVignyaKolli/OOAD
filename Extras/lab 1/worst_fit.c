#include<stdio.h>
#include<stdlib.h>

int np,nh;
int i,j;
int r[20],h[20];
int visit[20]={0};
int copy[20];


void minimum()
{
for(i=0;i<nh;i++)
{
for(j=0;j<nh;j++)
{
if(h[i]>h[j])
{
int temp=h[i];
h[i]=h[j];
h[j]=temp;
}
}
}

for(i=0;i<nh;i++);
printf("%d\n",h[i]);

}




int main()
{
int k;
printf("enter the no. of processes\n");
scanf("%d",&np);

printf("enter each requirements\n");
for(i=0;i<np;i++)
{
scanf("%d",&r[i]);
}
printf("enter the no. of holes\n");
scanf("%d",&nh);

printf("enter the hole size\n");
for(i=0;i<nh;i++)
{
scanf("%d",&h[i]);
copy[i]=h[i];
}

minimum();

for(i=0;i<np;i++)
{
 for(j=0;j<nh;j++)
 {
  if(visit[j]==0)
  {
    if(r[i]<=h[j])
    { 
	    for(k=0;k<nh;k++)
		{
		if(h[j]==copy[k])
		{ if(visit[k]==0){
            printf("process %d in the %d hole\n",i,k);
            break;
		}}
		}
            visit[j]=1;
            break;
    }    
  }
 }
}


return 0;
}




   
  




