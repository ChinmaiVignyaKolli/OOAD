#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct student
 {
    char name[20];
    char rollno[20];
    char degree[20];
    char branch[20];
  };
  
  struct course
 {
   char cname[20];
   char cnumber[20];
   int credits;
   char offdept[20];
  };
  
  struct section
  { 
    int sid;
    char cnumber[20];
    int sem;
    int year;
    char faculty[20];
  };
  
  
 struct prereq
 {
   char cnumber[20];
   int prereqno;
 };
  
  
  struct gradereport
  {
  char rollno[20];
  int sid;
  char grade[20];
  };
  
  
  int main(void)
  {
    int i;
    FILE *fp1;
    fp1=fopen("studentfile.dat","a");
    
    struct student *s=malloc(sizeof(struct student));
    
    for(i=0;i<1;i++)
    {
          printf("enter the details of  the student\n");
          printf("enter the name\n");
          scanf("%s",s->name);
          fprintf(fp1,"%s",s->name);
          
          printf("enter rollno\n");
          scanf("%s",s->rollno);
          fprintf(fp1,"%s",s->rollno);
          
          printf("enter degree\n");
          scanf("%s",s->degree);
          fprintf(fp1,"%s",s->degree);
          
          printf("enter branch\n");
          scanf("%s",s->branch);
          fprintf(fp1,"%s",s->branch);
          
     }
     fclose(fp1);
     /*
     FILE *fp2;
     fp2=fopen("coursefile.dat","a");
     struct course *c=malloc(sizeof(struct student));
     
     for(i=0;i<1;i++)
     {  
        printf("enter the details of the course\n");
        printf("enter course name\n");
        scanf("%s",c->cname);
        fprintf(fp2,"%s",c->cname);
        
         printf("enter course number\n");
         scanf("%s",c->cnumber);
         fprintf(fp2,"%s",c->cnumber);
          
         printf("enter credits\n");
         scanf("%d",&c->credits);
         fprintf(fp2,"%d",c->credits);
          
         printf("enter offering dept\n");
         scanf("%s",c->offdept);
         fprintf(fp2,"%s",c->offdept);
          
     }      
       fclose(fp2);     
     
     FILE *fp3;
     fp3=fopen("sectionfile.dat","a");
     struct section *d=malloc(sizeof(struct student));
     
     for(i=0;i<1;i++)
     {  
        printf("enter the details of the section\n");
        printf("enter section identity\n");
        scanf("%d",&d->sid);
        fprintf(fp3,"%d",d->sid);
        
         printf("enter course number\n");
         scanf("%s",d->cnumber);
         fprintf(fp3,"%s",d->cnumber);
          
         printf("enter semester\n");
         scanf("%d",&d->sem);
         fprintf(fp3,"%d",d->sem);
          
         printf("enter year\n");
         scanf("%d",&d->year);
         fprintf(fp3,"%d",d->year);
         
         printf("enter faculty\n");
         scanf("%s",d->faculty);
         fprintf(fp3,"%s",d->faculty);
          
     }     
       fclose(fp3);
         
       FILE *fp4;
     fp4=fopen("prereqfile.dat","a");
     struct prereq *p=malloc(sizeof(struct student));
     
     for(i=0;i<1;i++)
     {  
        printf("enter the details of the prerequisites\n");
        printf("enter course number\n");
        scanf("%s",p->cnumber);
        fprintf(fp4,"%s",p->cnumber);
        
         printf("enter prerequisite number\n");
         scanf("%d",&p->prereqno);
         fprintf(fp4,"%d",p->prereqno);
          
     }  
       fclose(fp4);      
      
      FILE *fp5;
     fp5=fopen("gradereport.dat","a");
     struct gradereport *g=malloc(sizeof(struct student));
     
     for(i=0;i<1;i++)
     {  
        printf("enter the details of the gradereport\n");
        printf("enter rollno\n");
        scanf("%s",g->rollno);
        fprintf(fp5,"%s",g->rollno);
        
         printf("enter section identity\n");
         scanf("%d",&g->sid);
         fprintf(fp5,"%d",g->sid);
          
         printf("enter grade\n");
         scanf("%s",g->grade);
         fprintf(fp5,"%s",g->grade);
          
     }   
       fclose(fp5);
  */     
  // search file
 char key[20];
 fp1=fopen("studentfile.dat","r");
 printf("enter rollno\n");
 scanf("%s",key);
 while(fscanf(fp1,"%s%s",s->name,s->rollno)==3); 
 
 if(strcmp(key,s->rollno)==0)
 
printf("\n %s%s\n",s->rollno,s->name); 
fclose(fp1);

   return(0);
       }    
         
     
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
    
     
       
  
  
  
  
  
    
   
    
    
    


