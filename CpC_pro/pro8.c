#include<stdio.h>
#include<stdlib.h>
struct node
{
	char ssn[25],name[25],dept[10],designation[25],phno;
	int sal;
	struct node*prev;
	struct node*next;
};
typedef struct node *NODE;
NODE first=NULL;
int count=0;
NODE createemployee()
{
	NODE employee;
	employee=(NODE)malloc(sizeof(NODE));
	printf("ENter the ssn,name,department,designation,salary,phoneno:\n");
	scanf("%s%s%s%s%d%s",(employee->ssn),(employee->name),(employee->dept),(employee->designation),&(employee->sal),(employee->phno));
	employee->prev=NULL;
	employee->next=NULL;
	count++;
	return employee;
}
NODE insertatfront()
{
	NODE newnode;
	newnode=createemployee();
	if(first=NULL)
	{
		return newnode;
	}
	newnode->next=first;
	first->prev=newnode;
	return newnode;
}

NODE deleteatfront()
{
	NODE ptr;
	if(first==NULL)
	{
		printf("Doubly linked list is empty\n");
		return NULL;
	}
	if(first->next==NULL)
	{
	printf("\n The employee node with the ssn:%s is deleted",(first->ssn));
	free(first);
	count--;
	return NULL;
	}
	ptr=first;
	first=first->next;
	ptr->next=NULL;
	first->prev=NULL;
	printf("The employee node with the ssn:%s is deleted",(ptr->ssn));
	free(ptr);
	return(first);
}
NODE insertatend()
{
	NODE newnode,ptr;
	newnode=createemployee();
	if(first==NULL)
	{
		return newnode;
	}
	ptr=first;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
	return first;
}
NODE deleteatend()
{
	NODE ptr,pprev;
	if(first==NULL)
	{
		printf("Doubly linked list is empty");
		return NULL;
	}
	if(first->next==NULL)
	{
		printf("\n The employee node with the ssn:%s is deleted",(first->ssn));
		free(first);
		count--;
		return NULL;
	}
	pprev=NULL;
	ptr=first;
	while(ptr->next!=NULL)
	{
		pprev=ptr;
		ptr=ptr->next;
	}
	ptr->prev=NULL;
	printf("The employee node with the ssn:%s is deleted",(ptr->ssn));
	free(ptr);
	pprev->next=NULL;
	count--;
	return first;
}
void displaystatus()
{
	NODE ptr;
	int nodeno=1;
	ptr=first;
	if(ptr==NULL)
		printf("no contents to display\n");
	while(ptr->next!=NULL)
	{
		printf("nodeno:%d",nodeno);
		printf("ssn:%s",(ptr->ssn));
		printf("Name:%s",(ptr->name));
		printf("department:%s",(ptr->dept));
		printf("designation:%s",(ptr->designation));
		printf("salary:%d",(ptr->sal));
		printf("phoneno:%s",&(ptr->phno));
		nodeno++;
	}
}
void doubleendedqueuedemo()
{
	int ch;
	do
	{
		printf("Demo double ended queue\n");
		printf("1)insert queue front\n 2)delete queue front\n 3)insert queue rear\n 4)delete queue rear\n 5) displat status\n 6) exit");
		printf("Enter your choice\n");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1: first=insertatfront();break;
		case 2: first=deleteatfront();break;
		case 3: first=insertatend();break;
		case 4: first=deleteatend();break;
		case 5: displaystatus();break;
		defeat: return;
	}
	}while(ch!=6);
}
 void main()
{
	int ch,i,n;
	do
	{
		printf("....Menu.......");
		printf("1) create DLL of employee Node\n 2)displaystatus\n3)insert at end \n 4) delete at front \n 5) insert at front\n 6) delete at front\n");
		printf("7) demo using csll\n 8)exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter number of employee\n");
			scanf("%d",&n);
			for(i=0;i<=n;i++)
				first=insertatend();
			break;
		case 2: displaystatus();break;
	        case 3: first=insertatend();break;
		case 4: first=deleteatfront();break;
		case 5: first=insertatfront();break;
		case 6: first=deleteatfront();break;
		case 7: doubleendedqueuedemo();break;
		case 8: exit(0);break;	
		}
	}while(ch!=8);
}

