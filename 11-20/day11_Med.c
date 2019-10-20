#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trie
{
	int end;
	struct trie *character[26];
};

struct trie* newTrieNode()
{
	struct trie *temp;
	int i;

	temp=(struct trie*)malloc(sizeof(struct trie));
	temp->end=0;
	for(i=0;i<26;i++)
	{
		temp->character[i]=NULL;
	}

	return temp;
	
}
struct trie* traverse(struct trie*,char*,int);
void autoComplete(struct trie*);

char data[15];
char maintain[15];
int counter=0;
int main()
{
	struct trie *start=NULL,*endNode=NULL,*temp=NULL;
	int n,i,j,len;
	

	start=newTrieNode();

	printf("Enter Number of words : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter %d Word : ",i);
		scanf("%s",data);

		temp=start;

		len=strlen(data);
		for(j=0;j<len;j++)
		{
			if(temp->character[data[j]-'a']==NULL)
			{
				temp->character[data[j]-'a']=newTrieNode();
				temp=temp->character[data[j]-'a'];
			}
			else
			{
				temp=temp->character[data[j]-'a'];
			}
		}
		temp->end=1;
			
	}

	while(1)
	{
	
	printf("Enter word to Autocomplete : ");
	scanf("%s",data);


	len=strlen(data);

	endNode=traverse(start,data,len);
	
	if(endNode!=NULL)
	{
		autoComplete(endNode);
	}
	else
		printf("No word start with this prefix\n");
	
	}	
	return 0;
}

struct trie* traverse(struct trie *temp,char *data,int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		temp=temp->character[data[i]-'a'];

		if(temp==NULL)
			return NULL;
	}

	return temp;
}

void autoComplete(struct trie *temp)
{
	int i;

	if(temp->end==1)
	{
		printf("%s%s\n",data,maintain);
	}
	for(i=0;i<26;i++)
	{
		if(temp->character[i]!=NULL)
		{
			maintain[counter]='a'+i;
			counter++;
			maintain[counter]='\0';

			autoComplete(temp->character[i]);
			
			counter--;
			maintain[counter]='\0';
		}
		
	}
}
