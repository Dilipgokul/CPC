#include<stdio.h>
#include<ctype.h>
#define size 5
char s[size];
int top=-1;
void push(char elem)
{
	s[++top]=elem;
}
char pop()
{
	return(s[top--]);
}
int precedence(char elem)
{
	switch(elem)
	{
		case '#':return 0;
		case '(':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '^':return 3;
		case '%':return 4;
	}
}
void main()
{
	char infx[50],pofx[50],elem,ch;
	int i,k;
	printf("Enter infx expression\n");
	scanf("%s",infx);
	push('#');
	while((ch=infx[i++])!='\0');
	{
		if(ch=='(')
			push(ch);
		else if(isalnum(ch))
			pofx[k++]=ch;
		else if(ch==')')
		{
			while(s[top]!='(')
				pofx[k++]=pop();
			elem=pop();
		}	
		else
		{
			while(precedence(s[top])>precedence(ch))
				pofx[k++]=pop();
			push(ch);
		}
	}
		while(s[top]!='#')
		pofx[k++]=pop();
		pofx[k]='\0';
		printf("\n given infc expn is : %s and postfix expn is:%s",infx,pofx);
	
}
