#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main()
{
  int sockfd;
  sockaddr_in client_addr;

  sockfd=socket(PF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
cout<<"socket connectn error"<<endl;
}

  client_addr.sin_family=AF_INET;
  client_addr.sin_port=htons(2500);
 // client_addr.sin_addr.s_addr=inet_addr("172.16.2.103");
//inet_aton("127.0.0.1",&(client_addr.sin_addr));
client_addr.sin_addr.s_addr = INADDR_ANY;
  memset(client_addr.sin_zero, '\0', sizeof client_addr.sin_zero);

  int temp=connect(sockfd,(struct sockaddr*)&client_addr, sizeof(client_addr));

  if(temp==-1)
{
    cout << "Connection error" << endl;
return -1;
} 
 else
    {
      cout << "connection established " << endl;
    }
  char buf[20];
  char rec_data[100];
 
  while(true)
    {
      cin >> buf;
      if(strcmp(buf,"shutdown")==0)
	 break;
      temp=send(sockfd,buf,sizeof buf,0);
      
      if(temp==-1)
	cout << "Error:not sent" << endl;
      else
	cout << "Sent " << temp << " bytes" << endl;
      
     int d=recv(sockfd,rec_data,sizeof rec_data,0);
if(d<0)
{
cout<<"error in receiving"<<endl;
break;
}
      cout << rec_data << endl;
    }
  close(sockfd);
  return 0;
}
