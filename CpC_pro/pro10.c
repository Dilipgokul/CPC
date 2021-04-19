#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST*lchild;
	struct BST*rchild;
};
typedef struct BST *NODE;
NODE create()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct BST));
	printf("Enter the data\n");
	scanf("%d",&temp->data);
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}
void insert(NODE root,NODE newnode)
{
	if(newnode->data<root->data)
	{
		if(root->lchild==NULL)
			root->lchild=newnode;
		else
			insert(root->lchild,newnode);
	}
	if(newnode->data>root->data)
	{
		if(root->rchild==NULL)
			root->rchild=newnode;
		else
			insert(root->rchild,newnode);
	}
}
void search(NODE root)
{
	if(root==NULL)
	{
		printf("BST is empty");
		return;
	}
	int key;
	NODE curr;
	printf("Enter the item to be searched\n");
	scanf("%d",&key);
	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("Entered key is present\n");
			return;
		}
		if(key>curr->data)
			curr=curr->rchild;
		else
			curr=curr->lchild;
	}
	printf("Entered value not present\n");
}
void inorder(NODE root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d",root->data);
		inorder(root->rchild);
	}
}
void preorder(NODE root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void postorder(NODE root)
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d",root->data);
	}
}
void main()
{
 NODE root=NULL,newnode;
 int ch,i,n;
	do{
		printf("\n.......MENU.....\n");
		printf("1)create\n2)search\n3)traversal\n4)exit\n\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter number of elements\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					newnode=create();
					if(root==NULL)
						root=newnode;
					else
						insert(root,newnode);
				}
				break;
			case 2:search(root);break;
			case 3:	if(root==NULL)
					printf("BST is empty\n");
				else
				{
				printf("\n Preorder traversal\n");
				preorder(root);
				printf("inorder traversal\n");
				inorder(root);
				printf("\n POst order traversal\n");
				postorder(root);
				}
				break;
			case 4:exit(0);break;	
		}
	}while(ch!=4);
}		
				
