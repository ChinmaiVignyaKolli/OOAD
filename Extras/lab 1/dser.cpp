#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>
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
}

soc.sin_family=AF_INET;
soc.sin_port=htons(3000);
soc.sin_addr.s_addr=INADDR_ANY;

memset(soc.sin_zero,'\0',sizeof soc.sin_zero);

//binding

int b;
b=bind(socfd,(struct sockaddr*)&soc,sizeof soc);
if(b<0)
{
cout<<"error";
}
else
{cout<<"binding established\n";
}

//listening

int l;
l=listen(socfd,20);
if(l<0)
{
cout<<"error";
}
else
{cout<<"listening....\n";
}

//accepting

struct sockaddr_in client;
socklen_t client_size = sizeof client;
int nc;
time_t result;
nc=accept(socfd,(struct sockaddr*)&client,&client_size);
if(nc<0)
{
cout<<"error";
}
else
{
cout<<"connection established\n";
char data[100];

result=time(NULL);
int f=snprintf(data,100,"%s",ctime(&result));
send(nc,data,sizeof data,0);
}

close(socfd);
close(nc);
return 0;
}
