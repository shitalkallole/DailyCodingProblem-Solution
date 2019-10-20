#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	struct node *child;
	int len;
};

struct node* newMem(int len)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp->child=NULL;
	temp->len=len;


	return temp;
}
int countLength(struct node *root)
{
	int l=0;
	while(root!=NULL)
	{
		l=l+(root->len)+1;
		root=root->child;
	}

	return (l-1);

}
int main()
{
	char data[100];
	int i,strLength,count=0,file=0,totalLength=0,initial=0,finalLength=0;
	struct node *root=NULL,*temp=NULL;

	printf("Enter sys Directory: ");
	scanf("%s",data);
	
	
	strLength=strlen(data);
	

	while(i<strLength)
	{
		if(data[i]!='\\')
			count++;
		else
		{
			root=newMem(count);
			temp=root;

			i=i+2;
			break;
		}
		i++;
	}

	while(i<strLength)
	{
		if(data[i]=='\\')
		{
			i++;

			if(data[i]=='n')
			{
				temp=root;
				i++;
			}
			else
			{
				if(temp->child==NULL)	
				{
					file=0;
					count=0;
					i++;
					while(data[i]!='\\' && i<strLength)
					{
						if(data[i]=='.')
							file=1;
						count++;
						i++;
					}					
					temp->child=newMem(count);
					temp=temp->child;

					if(file==1)
					{
						if(initial==0)
						{
							finalLength=countLength(root);
							initial=1;	
						}
						else
						{
							totalLength=countLength(root);
							if(totalLength>finalLength)
								finalLength=totalLength;
							
						}

					}
				}
				else
				{
					temp=temp->child;
					i++;

					if(data[i]!='\\')
					{
						file=0;
						count=0;
						while(data[i]!='\\' && i<strLength)
						{
							if(data[i]=='.')
								file=1;
							count++;
							i++;
						}	
						temp->len=count;

						if(file==1)
						{
							free(temp->child);
							temp->child=NULL;

							if(initial==0)
							{
								finalLength=countLength(root);
								initial=1;	
							}
							else
							{
								totalLength=countLength(root);
								if(totalLength>finalLength)
									finalLength=totalLength;
							}
			
						}	
					}//end of if
				}//end of else
			}//end of else
			
		}//end of if
	}//end of while	

	if(initial==1)
		printf("MAX:%d",finalLength);
	else
		printf("0");

	return 0;
}
