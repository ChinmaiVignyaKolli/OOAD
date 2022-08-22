#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main()
{
  int sockfd;
  struct sockaddr_in my_addr;
  int temp;
  sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket
  cout<<"socketfd is "<<sockfd<<endl;
if(sockfd<0)
{
cout<<"socket creation error"<<endl;
}
  my_addr.sin_family=AF_INET;
  my_addr.sin_port=htons(2500);
//  my_addr.sin_addr.s_addr=inet_addr("192.168.2.120");
	my_addr.sin_addr.s_addr=INADDR_ANY;
  memset(my_addr.sin_zero, '\0', sizeof(my_addr.sin_zero));

   temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  if(temp==-1)
{
    cout << "bind error" << endl;
    return -1;
} 
 else
    {
      cout << "binded" << endl;
    }

  int d=listen(sockfd,10);
if(d==-1)
{
cout<<"listen_error"<<endl;
return -1;
}
else
{
cout<<"Listening"<<endl;
}
  struct sockaddr_in client_addr;
  socklen_t client_size=sizeof client_addr;
  int client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
if(client_fd==-1)
{
  cout << "Accepted connection " << client_fd << endl;
 }
else
{
cout<<"connection accepted"<<endl;
}    

 
 int sz;
cout<<"enter the data size"<<endl;
cin>>sz;
 char c1[sz+8]; // after appending 0's 
 char c2[9];   // divisor poly
 char c3[20];  
 char c4[9];   // first 9 bits of c1
 char c5[9];  // remainder 
 char c6[9];
 char c7[sz];   // initial msg
 int j=0;
 cout<<"enter the input data"<<endl;
 for(int i=0;i<sz;i++)
   {
     cin>>c7[i];
   }
cout<<"data ";
for(int k=0;k<sz;k++)
{
cout<<c7[k];   // taking original data
}
for(int k=0;k<sz;k++)
{
c1[k]=c7[k];  // copying into c1 
}
for(int k=sz;k<sz+8;k++)
{
c1[k]='0';    // appending 8 zeroes
}
cout<<"\ndata+dup crc ";
for(int i=0;i<sz+8;i++)
{
cout<<c1[i];
}

for(int i=0;i<9;i++)
   {
     c2[i]='0';  // initializing divisor polynomial
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
cout<<j<<endl;
cout<<ind<<endl;
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
for(int k=0;k<sz;k++)
{
c3[k]=c1[k];
}
int h=1;
for(int k=sz;k<sz+8;k++)
{
c3[k]=c5[h];
h++;
}
cout<<endl<<"c3 ";
for(int k=0;k<sz+8;k++)
{
cout<<c3[k];
}



cout<<"num of bits u want to manipulate"<<endl;
cin>>t;
int n;
for(int k=0;k<t;k++)
{
cout<<"enter the bit num"<<endl;
cin>>n;
if(c3[n-1]=='0')
{
c3[n-1]='1';
}
else if(c3[n-1]=='1')
{
c3[n-1]='0';
}
}
cout<<endl<<"c3 ";
for(int k=0;k<sz+8;k++)
{
cout<<c3[k];
}
cout<<endl<<sizeof(c3)<<endl;
char recv_buf[100];
temp=send(client_fd,c3,sizeof c3,0);
if(temp<0)
{
cout<<"error in sending data"<<endl;
}
else
{
cout<<"data sent"<<endl;
}

/*
temp=recv(client_fd,recv_buf,sizeof recv_buf,0);
if(temp<0)
{
cout<<"error in receiving data"<<endl;
}
else
{
cout<<"data received as "<<recv_buf<<endl;
}
*/

close(client_fd);
close(sockfd);
return 0;
}
