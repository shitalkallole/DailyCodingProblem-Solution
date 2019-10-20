#include<stdio.h>
#include<stdlib.h>

int* (*call)();

typedef int* (*ptr)();	
ptr cons(int a,int b)
{
	
	//auto int* pair();
	int* pair()
	{
		int *data=(int*)malloc(sizeof(int)*2);
		data[0]=a;
		data[1]=b;
		printf("called");	
		return data;		
	}	
	return(pair);
	
}

void car()
{
	//int* (*call)();
	//call=cons(20,30);
	//int *data=(*call)();
	//printf("d:%d\n",data[0]);
	//printf("%x",call);
	int *data=(*call)();
	printf("%d\n",data[0]);
}
void cdr(int* (*call)())
{
	int *data=(*call)();
	printf("%d\n",data[1]);
}
int main()
{
	int a,b;
	
	printf("Enter a,b : ");
	scanf("%d%d",&a,&b);
	
	//call=cons(a,b);
	//int *data=(*call)();
	//printf("d:%d\n",data[0]);	

	//printf("%x\n",call);
	//car();
	call=cons(a,b);
	car();
	//cdr(cons(a,b));
	return 0;
}

