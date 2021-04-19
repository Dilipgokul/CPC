#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
double compute(char symbol,double op1,double op2)
{
	switch(symbol)
	{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		case '^': return pow(op1,op2);
		default: return 0;
	}
}
void main()
{
char symbol,pofx[50];
int i,top=-1;
double s[20],op1,op2,res;
printf("Enter your postfix expression\n");
gets(pofx);
for(i=0;i<strlen(pofx);i++)
{
	symbol=pofx[i];
	if(isdigit(symbol))
		s[++top]=symbol-'0';
	else
	{	
		op2=s[top--];
		op1=s[top--];
		res=compute(symbol,op1,op2);
		s[++top]=res;
	}
}
res=s[top--];
printf("the result is %f\n",res);
}
