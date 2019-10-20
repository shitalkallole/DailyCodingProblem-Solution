#include<stdio.h>
#include<string.h>

char decode[25];
int global=0;

void call(char*,int,int);
int main()
{
	char msg[26];
	int len;

	printf("Enter Message: ");
	scanf("%s",msg);

	len=strlen(msg);

	call(msg,len,0);
	return 0;
}

void call(char *msg,int len,int cur)
{
	int act=10;

	if(cur<len)
	{

		if(msg[cur]=='1')
		{
			if(((cur+1)<len) && (msg[cur+1]=='0'))
			{
				decode[global]=96+10;
				decode[global+1]='\0';

				global++;
	
				call(msg,len,(cur+2));

				global--;	
			}
			else
			{
				decode[global]=97;
				decode[global+1]='\0';
				global++;
				
				call(msg,len,(cur+1));

				global--;


				if((cur+1)<len)
				{
					decode[global]=96+10+(msg[cur+1]-'0');
					decode[global+1]='\0';

					global++;
	
					call(msg,len,(cur+2));

					global--;

				}
			}
		}
		else if(msg[cur]=='2')
		{
			if(((cur+1)<len)&& (msg[cur+1]=='0'))
			{
				decode[global]=96+20;
				decode[global+1]='\0';

				global++;
	
				call(msg,len,(cur+2));

				global--;

			}
			else
			{
				decode[global]=98;
				decode[global+1]='\0';
				global++;
				
				call(msg,len,(cur+1));

				global--;

				if((cur+1)<len)
				{
					act=msg[cur+1]-'0';
					if(act>=1 && act<=6)
					{
						decode[global]=96+20+act;
						decode[global+1]='\0';
						global++;
						call(msg,len,(cur+2));
						global--;
					}

				}
			}
		}
		else
		{
			decode[global]=(msg[cur]-'0')+96;
			decode[global+1]='\0';

			global++;
	
			call(msg,len,(cur+1));

			global--;
		}			
	}
	else
	{
		printf("%s\n",decode);
	}


}
