#include<stdio.h>
#include<stdlib.h>
char pat[50],str[50],rep[50],ans[50];
int i,j,k,c,m,flag=0;

void stringmatch()
{
i=j=m=c=0;
while(str[c]!='\0')
{
	if(str[m]==pat[i])
	{
		i++;
		m++;
		if(pat[i]=='\0')
		{
			flag=1;
			for(k=0;rep[k]!='\0';j++,k++)
			{
				ans[j]=rep[k];
			}
		i=0;
		c=m;
		}
	}
	else
	{
		ans[j]=str[c];
		j++;
		c++;
		m=c;
		i=0;
	}
}
ans[j]='\0';
}
void main()
{
	printf("Enter main string,pattern string and replace string\n");
	gets(str);
	gets(pat);
	gets(rep);
	stringmatch();
	if(flag==1)
		printf("The resultant string is\n%s",ans);
	else
		printf("\nPattern string not found\n");
}
