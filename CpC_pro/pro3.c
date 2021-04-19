#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size],top=-1;
void push();
void pop();
void pali();
void display();
void main()
{
	int choice;
	do{
	printf("\n.......MENU.......\n");
	printf("1)push\n2)pop\n3)palindrome\n4)display\n5)exit\n\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: push();break;
		case 2: pop();break;
		case 3: pali();break;
		case 4: display();break;
		case 5: exit(0);break;
		default: printf("invalid input\n");break;
	}
	}while(choice!=5);
	
}
void push()
{
	int item;
	if(top==size)
		printf("Stack is full\n");
	else
	{
	printf("Enter the item to insert\n");
	scanf("%d",&item);
	top=top+1;
	stack[top]=item;
	}
}
void pop()
{
	if(top==-1)
		printf("stack empty\n");
	else
	{
	printf("The deleted element is %d",stack[top]);
	top=top-1;
	}
}
void pali()
{
	int ind=0,i,j,k,digit,num[size],rev[size],len=top+1,length=0;
	while(top!=-1)
	{
		digit=stack[top];
		num[i]=digit;
		top--;
		i++;
	}
	printf("the entered numbers are\n");
	for(j=0;j<len;j++)
		printf("%d\t",num[j]);
	for(k=len-1;k>=0;k--)
	{
		rev[k]=num[ind];
		ind++;
	}
	printf("The reversed elements are\n");
	for(k=0;k<len;k++)
		printf("%d\t",rev[k]);
	printf("Check for palindrome\n");
	for(i=0;i<len;i++)
	{
		if(num[i]==rev[i])
			{
				length++;
			}
	}
	if(length==len)
		printf("It is a palindrome\n");
	else
		printf("It is not a palindrome\n");
	top=len-1;
}
void display()
{	int i;
	if(top==-1)
		printf("NO elements to display\n");
	else
	{
	printf("\n The elements are\n");
	for(i=top;i>=0;i--)
		printf("%d\t",stack[i]);
	}
}
