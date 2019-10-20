#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j=0,temp,got=0;
	int *data,assign;

	printf("Enter Array Size : ");
	scanf("%d",&n);

	data=(int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}

	for(i=1;i<n;i++)
	{
		if(data[i]<=0)
		{
			temp=data[j];
			data[j]=data[i];
			data[i]=temp;
			j++;
		}
	}

	for(i=0;i<j;i++)
	{
		if(data[i]<0)
			data[i]=-data[i];
	}
	for(i=j;i<n;i++)
	{
		assign=data[i];
		if(assign<0)
			assign=-assign;
		if((assign<=n) && (data[assign-1]>=0))
		{
			if(data[assign-1]==0)
				data[assign-1]=-1;
			else
				data[assign-1]=-data[assign-1];
			
		}	
	}

	for(i=0;i<n;i++)
	{
		if(data[i]>=0)
		{
			printf("%d",(i+1));
			got=1;
			break;
		}
	}
	if(got==0)
		printf("%d",(i+1));
	return 0;	
}
