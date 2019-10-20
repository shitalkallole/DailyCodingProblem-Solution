#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int firsttime=1,pos=0;
char path[20];
struct node *start=NULL;

struct node* newNode(int);
void generateTree(struct node *);
void preorder(struct node *);

int main()
{

	printf("Enter Serialization path : ");
	scanf("%s",path);

	generateTree(start);
	
	printf("Preorder Path : ");
	preorder(start);
	return 0;
}

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
	
}
void generateTree(struct node *ptr)
{
	if(firsttime)
	{
		firsttime=0;

		start=newNode(path[pos]-48);
		pos++;
	
		if(path[pos]!='N')
		{
			start->left=newNode(path[pos]-48);
			pos++;
			generateTree(start->left);	
		}
		else
		{
			start->left=NULL;
			pos++;
		}

		if(path[pos]!='N')
		{
			start->right=newNode(path[pos]-48);
			pos++;
			generateTree(start->right);
		}	
		else
		{
			start->right=NULL;
		}
	}
	else
	{
		if(path[pos]!='N')
		{
			ptr->left=newNode(path[pos]-48);
			pos++;
			generateTree(ptr->left);
		}
		else
		{
			pos++;
		}
		if(path[pos]!='N')
		{
			ptr->right=newNode(path[pos]-48);
			pos++;
			generateTree(ptr->right);
		}
		else
		{
			pos++;
		}

	}
}
