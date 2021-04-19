#include<stdio.h>
#include<stdlib.h>
struct node
{
	char usn[25],name[25],branch[25],phno[10];
	int sem;
	struct node *next;
};
typedef struct node *NODE;
NODE head=NULL;
int count=0;
NODE create()
{
	NODE student;
	student=(NODE)malloc(sizeof(struct node));
	printf("Enter usn,name,branch,phoneno,sem\n");
	scanf("%s%s%s%s%d",(student->usn),(student->name),(student->branch),(student->phno),&(student->sem));
	student->next=NULL;
	count++;
	return student;
}
NODE insert_at_front()
{
	NODE p;
	p=create();
	if(head==NULL)
		return p;
	p->next=head;
	return p;
}
NODE delete_at_front()
{
	NODE p;
	if(head==NULL)
	{
		printf("Linked list is empty\n");
		return NULL;
	}
	if(head->next==NULL)
	{
		printf("The student node with use: %s is deleted",head->usn);
		count--;
		return NULL;
	}
	p=head;
	head=head->next;
	printf("The student node with usn: %d is deleted",(p->usn));
	free(p);
	return head;
	count--;
}
NODE insert_at_end()
{
	NODE p,q;
	p=create();
	if(head==NULL)
		return p;
	q=head;
	while(q->next!=NULL)
		q=q->next;
	q->next=p;
	return head;
}
NODE delete_at_end()
{
	NODE p,prep;
	if(head==NULL);
	{
		printf("Linked list is empty\n");
		return NULL;
	}
	if(head->next=NULL)
	{
		printf("The student node with usn: %s is deleted",head->usn);
		free(head);return NULL;count--;
	}
	p=head;prep=NULL;
	while(p->next!=NULL)
	{
		prep=p;
		p=p->next;
	}
	printf("The student node with usn: %s is deleted",p->usn);
	free(p);
	prep->next=NULL;
	count--;
	return head;
}
void display()
{
	NODE p;
	int nodeno=1;
	p=head;
	if(p==NULL)
	{
		printf("No contents to display\n");
		return;
	}
	printf("The contents of linked list are:\n");
	while(p!=NULL)
	{
		printf("\n%d\n",nodeno);
		printf("\nUSN:%s\n",(p->usn));
		printf("\nName:%s\n",(p->name));
		printf("\nBranch:%s\n",(p->branch));
		printf("\nPhone no:%s\n",(p->phno));
		printf("\nSem:%d\n",(p->sem));
		p=p->next;nodeno++;
	}
}
void stackdemo()
{
	int ch;
	do{
		printf("\n.........Stack demo using Sll..........\n");
		printf("\n1)push operation\n2)pop operaion\n3) display\n 4)exit\n\n Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: head=insert_at_end();break;
			case 2: head=delete_at_front();break;
			case 3: display();break;
			case 4: exit(0);break;
		}
	   }while(ch!=4);	
}
void main()
{
	int ch,i,n;
	do{
		printf("\n......MENU......\n");
		printf("1) create Sll\n2) Display status\n3) insert at front\n4)insert at end\n5)delete at front\n6)delete at end\n7)stack demo using sll\n8)exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter the number of students\n");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
				head=insert_at_front();break;
		case 2: display();break;
		case 3: head=insert_at_front();break;
		case 4: head=insert_at_end();break;
		case 5: head=delete_at_front();break;
		case 6: head=delete_at_end();break;
		case 7: stackdemo();break;
		case 8: exit(0);break;
		}
	}while(ch!=8);
}
