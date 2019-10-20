#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data)
{
	struct node *allocate;

	allocate=(struct node*)malloc(sizeof(struct node)*1);

	allocate->data=data;
	allocate->left=NULL;
	allocate->right=NULL;

	return allocate;

}

void preorder(struct node *start)
{
	if(start!=NULL)
	{
		printf("%d ",start->data);		
		preorder(start->left);
		preorder(start->right);
	}
	else
		printf("N ");
}

int main()
{
	int totalNodes,i,j,data;
	char path[10];
	int len;

	struct node *start=NULL;
	struct node *temp=NULL;

	printf("Enter Total Nodes : ");
	scanf("%d",&totalNodes);

	for(i=0;i<totalNodes;i++)
	{
		temp=start;

		printf("Enter %d Node :",(i+1));
		scanf("%s%d",path,&data);
		
		len=strlen(path);
		len--;

		for(j=0;j<len;j++)
		{
			if(path[j]=='L')
				temp=temp->left;
			else
				temp=temp->right;
		}
			
		if(path[j]=='T')
		{
			start=newNode(data);			
		}
		else if(path[j]=='L')
		{
			temp->left=newNode(data);
		}	
		else
		{
			temp->right=newNode(data);
		}

	}
	
	printf("Encoded String : ");		
	preorder(start);
	
	return 0;
}
