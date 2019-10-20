#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node* returnRootNode(int,int);
int solveExp(struct node *);
struct node
{
	char op;
	int data;
	struct node *left;
	struct node *right;
};

int main()
{
	int n,height,ans;
	struct node *root;

	printf("Enter No of Nodes Present in Tree : ");		
	scanf("%d",&n);	

	printf("Enter Height of the tree : ");//used to allocate size of string which hold the path
	scanf("%d",&height);

	root=returnRootNode(n,height);//function going to create the tree

	ans=solveExp(root);

	printf("Ans: %d ",ans);
	return 0;
}

int solveExp(struct node *root)
{
	int no1,no2;
	if(root->op=='$')
		return root->data;
	else
	{

		no1=solveExp(root->left);
		no2=solveExp(root->right);

		if(root->op!='$')
		{
			if(root->op=='+')
				return (no1+no2);
			else if(root->op=='-')
				return (no1-no2);
			else if(root->op=='*')
				return (no1*no2);
			else
				return (no1/no2);
		}
		
	}
}
struct node* returnRootNode(int n,int height)
{
	struct node *root=NULL,*tempRoot=NULL,*allocateMem=NULL;

	int i,j;
	int data;
	int length;
	char op;

	char *path;

	path=(char*)malloc(sizeof(char)*height);
	for(i=0;i<n;i++)
	{
		printf("Enter %d node path,operator and data : ",(i+1));
		scanf("%s %c %d",path,&op,&data);

		if(path[0]=='m' || path[0]=='M')//m=main i.e root
		{
			root=(struct node*)malloc(sizeof(struct node));
			root->op=op;
			root->data=data;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			tempRoot=root;

			length=strlen(path);
			for(j=0;j<length-1;j++)
			{
				if(path[j]=='l' || path[j]=='L')
					tempRoot=tempRoot->left;
				else
					tempRoot=tempRoot->right;				
			}	
			allocateMem=(struct node*)malloc(sizeof(struct node));
			allocateMem->op=op;
			allocateMem->data=data;
			allocateMem->left=NULL;
			allocateMem->right=NULL;
		
			
			if(path[j]=='l' || path[j]=='L')
				tempRoot->left=allocateMem;
			else
				tempRoot->right=allocateMem;			
		}
	}

	return root;

}
