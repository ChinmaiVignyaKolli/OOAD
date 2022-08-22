#include<iostream>
#include<cmath>

using namespace std;

int friends[7][7],enemies[7][7];

void bits(int a)
{
	int c,d,e,f,s,q;
	int r,i=1,j=0;
	for(s=0;s<7;s++)
	{
		for(q=0;q<7;q++)
		{
			friends[s][q]=0;
			enemies[s][q]=1;
		}
	}
	
	while(a>0)
	{
		r=a%2;
		friends[i][j]=friends[j][i]=r;
		enemies[i][j]=enemies[j][i]=r!=0?0:1;
		j++;

		if(i==j)
		{
			i++;
			j=0;
		}
		a=a/2;
	}
	
	
}

int ramsey(int count)
{
int i,j,k,flag=0,l,m,n;

	flag=0;
	cout<<count<<endl;
		bits(count);		
		for(i=1;i<7;i++)
		{
			for(j=0;j<7;j++)
			{
				if(friends[i][j]==1)
					{
						
						for(k=0;k<7;k++)
						{
							if(friends[j][k]==1)
								{
									if(friends[i][k]==1)
									{
										flag=1;
										
										break;
									}
						
								}
						}
					}
			}
		}
		
		for(l=1;l<7;l++)
		{
			
			for(m=0;m<7;m++)
			{
				
				if(enemies[l][m]==1)
					{
						
						for(n=0;n<7;n++)
						{
							if(enemies[m][n]==1)
								{
									if(enemies[n][l]==1)
									{
  										         				
							  		        flag=1;							
										break;
									}
						
								}
						}
					}
			}
		}
		


	return (flag);
}
int main(void)
{	
	int i=0,j=0,flag1=0,flag2=0,k=0;
	long int counter=1;
	while(counter<pow(2,21))
	{
		flag1=ramsey(counter);
		if(flag1==1)
		{
			counter++;
		}
		else
		{
			flag2=1;
			cout<<"false claim"<<endl;
			break;
		}
	}
	if(flag2==0)
	cout<<"Claim verified"<<endl;
}


