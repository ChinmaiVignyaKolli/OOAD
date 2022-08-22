#define relation 1
#define fds 3
#define attributes 6
#define candi 2
#define primary 0
int can[attributes]={0,1,1,0,0,0};
int rel[fds][attributes]=
	{//1-left 2-right 3-none
		{1,2,2,2,2,2},
		{2,1,1,2,2,2},
		{3,3,3,1,2,3}
	};
#include<iostream>
using namespace std;
int main()
	{
	int cand;
	for(int i=0;i<fds;i++)
		{
		cand=0;
		for(int i1=0;i1<attributes;i1++)
			if( (can[i1]==1 && rel[i][i1]==1) || (i1==primary && rel[i][i1]==1) )
				cand++;
		if(cand==0)
			cout<<"fd "<<i+1<<" is not in 3nf \n";
		else
			cout<<"fd "<<i+1<<" is in 3nf \n";
		}
	return 0;
	}
