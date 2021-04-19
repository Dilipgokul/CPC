#include<stdio.h>
#include<stdlib.h>
int count=0,*ht;
int ndex,n,m,key[20];
void insert(int key)
{
	ndex=key%m;
	while(ht[ndex]!=-1)
		ndex=(ndex+1)%m;
	ht[ndex]=key;
	count++;
}
void display()
{	int i;
	if(count==0)	
	{
		printf("No elements to display\n");
		return;
	}
	printf("The contents of the hast table are:\n");
	for(i=0;i<m;i++)
	printf("\nT[%d]-->%d\n",i,ht[i]);
}
void main()
{
int i;
printf("enter the number of records\n");
scanf("%d",&n);
printf("enter the two digit memory location for hast table\n");
scanf("%d",&m);
ht=(int*)malloc(m*sizeof(int));
for(i=0;i<m;i++)
ht[i]=-1;
printf("Enter the four digit key values\n");
for(i=0;i<n;i++)
scanf("%d",&key[i]);
for(i=0;i<n;i++)
{
	if(count==m)
	{
		printf("\nhash table is full\n");
	}
	insert(key[i]);
}
display();
}
