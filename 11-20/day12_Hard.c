#include<stdio.h>
char data[20];
int counter=0;

void numberOfStaircase(int n)
{
	if(n==0)
	{
		printf("%s\n",data);
	}
	if(n>0)
	{
		data[counter]='1';
		data[counter+1]='\0';
		counter++;
		numberOfStaircase(n-1);
		counter--;

		data[counter]='2';
		data[counter+1]='\0';
		counter++;
		numberOfStaircase(n-2);
		counter--;
	}
}


int main()
{
	int n;

	printf("Enter Staircase Steps : ");
	scanf("%d",&n);

	numberOfStaircase(n);

	return 0;
}

