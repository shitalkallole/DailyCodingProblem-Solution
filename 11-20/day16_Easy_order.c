#include<stdio.h>

int main()
{
	int data[5],q=-1,c=0,choice=1,id;

	printf("1.Order \n2.Get Last ith\n3.Exit\n");
	

	while(choice)
	{
		printf("Enter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter Id : ");
				scanf("%d",&id);

				q++;
				if(q>4)
					q=0;
				data[q]=id;
				c++;
				break;
			case 2:
				printf("\nEnter ith which u want: ");
				scanf("%d",&id);
		
				if(c<id)
				{
					printf("Not Exist\n");
					break;
				}
				id=id-1;
				
				if((q-id)>=0)
					printf("\n%d",data[q-id]);
				else
				{
					id=q-id;
					id=-id;
					printf("\n%d",data[5-id]);
				}
				break;
			case 3:
				choice=0;
				break;	
		}
	}

	return 0;
}
