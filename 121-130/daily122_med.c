#include<stdio.h>
#include<stdlib.h>

int **dptable;
int findMaxCoins(int**,int,int,int,int);
int main()
{
	int rows,cols,i,j,maxCoins;
	int **data;

	printf("Enter no of Rows: ");
	scanf("%d",&rows);
	
	printf("Enter no of Cols: ");
	scanf("%d",&cols);
		
	data=(int**)malloc(sizeof(int*)*rows);
	dptable=(int**)malloc(sizeof(int*)*rows);;

	for(i=0;i<rows;i++)
	{
		data[i]=(int*)malloc(sizeof(int)*cols);
		dptable[i]=(int*)malloc(sizeof(int)*cols);;
	}

	printf("Enter data:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			scanf("%d",&data[i][j]);
			dptable[i][j]=-1;
		}
	}

	
	maxCoins=findMaxCoins(data,0,0,rows,cols);
	printf("Max sum of coins : %d\n\n",maxCoins);

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d ",dptable[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int findMaxCoins(int **data,int i,int j,int r,int c)
{
	int sum1=data[i][j],sum2=data[i][j];

	if((j+1)<c)
	{
		if(dptable[i][j+1]!=-1)
			sum1=data[i][j]+dptable[i][j+1];
		else
			sum1=data[i][j]+findMaxCoins(data,i,(j+1),r,c);
	}	
	if((i+1)<r)
	{
		if(dptable[i+1][j]!=-1)
			sum2=data[i][j]+dptable[i+1][j];
		else
			sum2=data[i][j]+findMaxCoins(data,(i+1),j,r,c);

	}

	if(sum1>sum2)
		dptable[i][j]=sum1;
	else
		dptable[i][j]=sum2;

	if(sum1>sum2)
		return sum1;
	else
		return sum2;
}

