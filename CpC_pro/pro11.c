#include<stdio.h>
#include<stdlib.h>
int n,visited[50],a[50][50];
int q[50],front=-1,rear=-1;
int s[50],top=-1;
void bfs(int v)
{
	int i,cur;
	visited[v]=1;
	q[++rear]=v;
	while(front!=rear)
	{
		cur=q[++front];
		for(i=1;i<=n;i++)
		{
			if((a[cur][i]==1) && (visited[i]==0))
			{
				visited[i]=1;
				q[++rear]=i;
				printf("%d",i);
			}
		}
	}
}
void dfs(int v)
{
	int i;
	visited[v]=1;
	s[++top]=v;
	for(i=1;i<=n;i++)
	{
		if((a[v][i]==1) && visited[i]==0)
		{
			printf("%d",i);
			dfs(i);
		}
	}
}
void main()
{
	int i,j,ch,start;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjcency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
	visited[i]=0;
	printf("Enter the starting vertix\n");
	scanf("%d",&start);
	printf("\n==>1.BFS:print all the reachable vertix from the starting node:");
	printf("\n==>2.DFS:print all the reachable vertix from the starting node:");
	printf("\n==>3.exit\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("The reachable vertex from the starting node:%d are:\n",start);
			bfs(start);
			for(i=1;i<=n;i++)
			{
				if(visited[i]==0)
					printf("the vertex that is not reachable is %d\n",i);
			}
			break;
		case 2: printf("The reachable vertex from the starting node %d are:",start);
			dfs(start);
			break;
		case 3: exit(0);break;
	}
}
