#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *npx;

};
struct node *prev=0,*next=0;

struct node* newNode(int data)
{
	struct node *temp;

	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->npx=(int)prev^(int)next;

	return temp;
}

void print(struct node *visit)
{
	struct node *cal=0,*cur;
	
	if(visit!=NULL)
	{
		while(visit!=0)
		{
			printf("%d ",visit->data);
			cur=visit;
			visit=(int)visit->npx^(int)cal;
			cal=cur;
		}
	}
	else
		printf("Empty\n");
}
void getElement(int index,struct node *visit)
{
	struct node *cal=0,*cur;
	int cIndex=1,got=0;

	if(index<=0)
		printf("Please give correct Index\n");
	
	else
	{
	if(visit!=NULL)
	{
		while(visit!=0)
		{
			if(index==cIndex)
			{
				got=1;
				
				printf("%d\n",visit->data);
				break;
			}
			cur=visit;
			visit=(int)visit->npx^(int)cal;
			cal=cur;
			cIndex++;
		}
		if(got==0)
			printf("Index out range\n");

	}
	else
		printf("Empty\n");
	}
}
int main()
{
	struct node *start=NULL,*end=NULL;
	int choice,data,index;

	printf("1.Add Element\n2.Left to Right\n3.Right to Left\n4.Get Element At Index\n5.Exit\n ");
	while(1)
	{
		printf("Enter Your Choice : ");
		scanf("%d",&choice);

		if(choice==5)
			break;

		switch(choice)
		{
			case 1:
				printf("Enter Data:");
				scanf("%d",&data);

				if(start==NULL)
				{
					start=newNode(data);
					end=start;
					prev=start;	
				}
				else
				{
					end=newNode(data);
					prev->npx=(int)prev->npx^(int)end;
					prev=end;
				}
				break;
			case 2:
				print(start);
				break;
			case 3:
				print(end);
				break;
			case 4:
				printf("Enter Index (Start from 1):");
				scanf("%d",&index);
	
				getElement(index,start);
			
				break;
		}

	}

	return 0;
	
}
