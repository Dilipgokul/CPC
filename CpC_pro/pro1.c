#include<stdio.h>
#include<stdlib.h>
void createarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void displayarray(int a[],int n)
{	
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int insert_at_pos(int item,int a[],int n,int pos)
{
	int i;
	if(pos>n||pos<0)
	{
		printf("invalid position\n");
		return n;
	}
	for(i=n-1;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=item;
	return n+1;
}
int delete_at_pos(int a[],int n,int pos)
{
	int i;
	if(pos>=n||pos<0)
	{
		printf("Invalid input\n");
		return n;
	}
	printf("\nthe deleted element is %d",a[pos]);
	for(i=pos+1;i<n;i++)
	{
		a[i-1]=a[i];
	}
	return n-1;
}
int main()
{
int a[10],i,choice,n,item,pos;
for(;;)
{
printf("\n\n..........Menu...........\n");
printf("1)create an array\n 2) Display array\n3) Insert at position\n4)delete at position\n5)Exit\n\n Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
	case 1: printf("enter the number of elements");
		scanf("%d",&n);
		printf("\nenter the elements\n");
		createarray(a,n);
		break;
	case 2: printf("The contents of the array are:");
		displayarray(a,n);
		break;
	case 3: printf("Enter the position and item to be inserted\n");
		scanf("%d%d",&pos,&item);
		n=insert_at_pos(item,a,n,pos);
		break;
	case 4: printf("Enter the postion to be deleted");
		scanf("%d",&n);
		n=delete_at_pos(a,n,pos);
		break;
	case 5: exit(0);break;
	default:printf("invalid choice\n");
		break;
}
}
}
