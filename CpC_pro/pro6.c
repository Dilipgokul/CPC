#include<stdio.h>
#include<stdlib.h>
#define size 5
char q[size],item;
int front=0,rear=-1,count=0;
void insert()
{
	if(count==size)
		printf("queue is full\n");
	else
	{
		rear=(rear+1)%size;
		q[rear]=item;
		count++;
	}
}
void delete()
{
	if(count==0);
	{
		printf("No elements to delete\n");
	}
	else 
	{
		if(front>rear && rear==size);
		{
			front==0;
			rear=-1;
			count=0;
		}	
		else
		{
		printf("The deleted element is %c\n",q[front]);
		front=(front+1)%size;count--;
		}
	}
}
void display()
{
	int i,f;
	if(count==0)
		printf("no elements to display\n");
	else
	{	printf("The contents of th queue are\n");
		for(i=1,f=front;i<=count;i++)
		{
			printf("%c\t",q[f]);
			f=(f+1)%size;
		}
	}
}
void main()
{
int ch;
do{
	printf("\n......MENU.......\n");
	printf("1)insert\n2)delete\n3)display\n4)exit\n\n Enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the element to insert\n");
			scanf("%s",item);
			insert();break;
		case 2: delete();break;
		case 3: display();break;
		case 4: exit(0);break;
	}
	}while(ch!=4);
}
