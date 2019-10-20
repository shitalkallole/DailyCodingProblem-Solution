#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,add,temp,got=0;
	int *data,i,status[100];


	printf("Enter Add num : ");
	scanf("%d",&add);

	printf("Enter Total Elements : ");
	scanf("%d",&n);

	data=(int*)malloc(sizeof(int)*n);

	printf("Enter Elements (1 to 100):\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}

	for(i=0;i<100;i++)
		status[i]=0;

	for(i=0;i<n;i++)
	{
		temp=add-data[i];

		if(temp>=0)
		{

			if(status[temp]==1)
			{
				printf("%d %d : YES",data[i],temp);
				got=1;
				break;
			}	
			else
			{
				status[data[i]]=1;
			}
		}
	}

	if(got==0)
		printf("No Elements presents who's addition is %d\n",add);

	return 0;
}
