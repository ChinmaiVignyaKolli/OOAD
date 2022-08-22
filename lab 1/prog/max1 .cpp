// iterative binary search tree

#include<iostream>
#include<stdlib.h>
using namespace std;


struct node
{   int data;
	
	struct node *left;
	struct node *right;
}*root=NULL, *new_node,*current;

void insert(int value)
{   
    struct node *new_node;
	new_node= (struct node *)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(root==NULL)
	{
		root=new_node;
	}
	else
	{
		current=root;
		while(1)
		{
			if (new_node->data < current->data) // insert at left
			{
				if (current->left == NULL)
				{
					current->left=new_node;
					break;
				}
				current=current->left;	
									
			}
			else if(new_node->data > current->data)// insert at right
			{
				if(current->right == NULL)
				{
					current->right=new_node;
					break;
				}
				current=current->right;
				
			}
		}
	}
	
}


findmax(struct node *root)
{
	while(root->right != NULL)
	{
		root=root->right;
	}
	printf("maximum is %d", root->data);
}

void display(struct node *root) // implement recursive inoder 
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d->",root->data);
		display(root->right);
		
	}
	
}




main()
{
	int op, value,i;
	while(1)
	{
		cout<<"\n Enter your choice:\t 1. Insert \t 2.max 3. Exit ";
		cin>>op;
		
		switch(op)
		{
			case 1:
				cout<<"Enter the value";
				cin>>value;
				insert(value);
				display(root);
				break;
				
				case 2:	findmax(root);
					
					case 3:	exit(0);
					
						
						
		}
	}
}

