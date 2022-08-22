#include<iostream>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

int main()
{
int socfd;
struct sockaddr_in soc;
socfd=socket(PF_INET,SOCK_STREAM,0);
if(socfd<0)
{
cout<<"error\n ";
}
else
{
printf("socket with socfd: %d\n",socfd);


soc.sin_family=AF_INET;
soc.sin_port=htons(3000);
soc.sin_addr.s_addr=INADDR_ANY;

memset(soc.sin_zero,'\0',sizeof soc.sin_zero);

int nc;
nc=connect(socfd,(struct sockaddr*)&soc,sizeof soc);
if(nc<0)
{
cout<<"error";
}
else
{
cout<<"connection established\n";
int re_data[40];
int v=recv(nc,re_data,sizeof re_data,0);
if(v<0)
{
cout<<"error in receiving\n";
}
else
{
cout<<"date and time: \n"<<re_data;
}
}
}

close(socfd);
return 0;
}

