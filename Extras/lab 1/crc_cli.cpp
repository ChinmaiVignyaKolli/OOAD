#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include<unistd.h>

using namespace std;

int main()
{
  int sockfd;
  sockaddr_in client_addr;
int temp;

  sockfd=socket(PF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
cout<<"socket connectn error"<<endl;
}

  client_addr.sin_family=AF_INET;
  client_addr.sin_port=htons(2500);
  //client_addr.sin_addr.s_addr=inet_addr("192.168.3.181");
inet_aton("127.0.0.1",&(client_addr.sin_addr));
  memset(client_addr.sin_zero, '\0', sizeof client_addr.sin_zero);

   temp=connect(sockfd,(struct sockaddr*)&client_addr, sizeof(client_addr));

  if(temp==-1)
{
    cout << "Connection error" << endl;
return -1;
} 
 else
    {
      cout << "connection established " << endl;
    }
 int sz;
cout<<"enter the data size"<<endl;
cin>>sz;
char c1[sz+8];
temp=recv(sockfd,c1,sizeof c1,0);
if(temp<0)
{
cout<<"error in receiving data"<<endl;
}
else
{
cout<<"data received as "<<c1<<endl;
}
char c2[9];
 char c3[20];
 char c4[9];
 char c5[9];
 char c6[9];
 int j=0;
for(int i=0;i<9;i++)
   {
     c2[i]='0';
   }
 c2[0]='1';
 c2[6]='1';
 c2[7]='1';
 c2[8]='1';
cout<<endl;
cout<<"crc ";
for(int k=0;k<9;k++)
{
cout<<c2[k];
}
for(int i=0;i<9;i++)
   {
     c4[i]=c1[j];
     j++;
   }
cout<<endl;
cout<<"c4 ";
for(int k=0;k<9;k++)
{
cout<<c4[k];
}
int t=0;
int count,ind;
while(1)
{
for(int i=0;i<9;i++)
       {
	 count=0;
	 if(c2[i]=='1')
	   {
	     if(c4[i]=='1')
	       {
		 c5[i]='0';
	       }
	     else if(c4[i]=='0')
	       {
		 c5[i]='1';
	       }
	   }
	 else if(c2[i]=='0')
	   {
	     if(c4[i]=='1')
	       {
		 c5[i]='1';
	       }
	     else if(c4[i]=='0')
	       {
		 c5[i]='0';
	       }

	   }
       }
cout<<endl;
cout<<"c5 ";
     for(int k=0;k<9;k++)
       {
	cout<<c5[k];
       }
count=0;
     for(int k=0;k<9;k++)
       {
	 if(c5[k]=='1')
	   {
	     ind=k;
	     break;
	   }
	 else
	   {
	     count++;
	   }
       }
cout<<endl<<"indx";
cout<<ind<<endl;
  if(count==9)
       {
	 if(((sz+8)-j)<9)
	   {
	     for(int k=0;k<(9-((sz+8)-j));k++)
	       {
		 c5[k]='0';
	       }
            int z=(sz+8)-j;
	     for(int k=9-z;k<9;k++)
	       {
		 c5[k]=c1[j];
		 j++;
	       }
	     break;
	   }
	 else
	   {
	     for(int k=0;k<9;k++)
	       {
		 c5[k]=c1[j];
		 j++;
	       }
	   }
       }
else
       {
if(((sz+8-j)+(9-ind))>=9)
     {
	 for(int k=0;k<9;k++)
	   {
	     c6[k]=c5[k];
	   }
	 int y;
	 y=ind;
	 for(int k=0;k<9-y;k++)
	   {
	     c5[k]=c6[ind];
	     ind++;
	   }
	 for(int k=9-y;k<9;k++)
	   {
	     c5[k]=c1[j];
	     j++;
	   }
       }
else if(((sz+8-j)+(9-ind))<9)
    {
for(int k=0;k<9;k++)
{
    c6[k]=c5[k];
}
for(int k=0;k<(9-((sz+8-j)+(9-ind)));k++)
{
c5[k]='0';
}
int g=(9-((sz+8-j)+(9-ind)));
int f=ind;
for(int k=g;k<g+(9-ind);k++)
{
  c5[k]=c6[f];
   f++;
}
for(int k=g+(9-ind);k<9;k++)
{
c5[k]=c1[j];
j++;
}
j=sz+8+1;

}
}
cout<<"c4 ";
for(int k=0;k<9;k++)
       {
	cout<<c4[k];
       }
cout<<"c5 ";
for(int k=0;k<9;k++)
       {
	cout<<c5[k];
       }
for(int k=0;k<9;k++)
{
c4[k]=c5[k];
}
if(j>sz+8)
{
break;
}
}
char sent_buf[100];
count=0;
for(int k=0;k<9;k++)
{
if(c5[k]=='0')
{
count++;
}
}
if(count==9)
{
cout<<"Error Free !!"<<endl;
}
else
{
cout<<"Error !!"<<endl;
}
/*
temp=send(sockfd,sent_buf,sizeof sent_buf,0);
if(temp<0)
{
cout<<"error in sending data"<<endl;
}
else
{
cout<<"message sent"<<endl;
}
*/

close(sockfd);
return 0;
}
