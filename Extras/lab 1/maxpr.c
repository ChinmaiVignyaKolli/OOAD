#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{

 
 pid_t pid=1;
 int count=0;
 while(pid)
 {
   pid=fork();
   
 if(pid<0)
 {  
    break;
 }
 else if(pid==0)
 {
   //count++;
    exit(0);
    
 }

 else
 {
   count++;
   wait();
 }
}

  printf("max no. of processes : %d\n",count);
 return 0;
}
   
