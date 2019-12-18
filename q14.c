#include<stdio.h>
#include<stdlib.h>
 
#define TRUE 1
#define FALSE 0

typedef struct node *nodepointer;
typedef struct node
{
     nodepointer link;
    int vertex;
}node;
 
 
nodepointer G[20];   
nodepointer front, rear;
	
int visited[20];
int n,x;
 
void addq(int v)
{ 
	nodepointer temp, ptr;
	temp=(nodepointer)malloc(sizeof(node));
	temp->link=NULL;
	temp->vertex=v;
	if(front==NULL)
		front=temp;
	else
		rear->link=temp;
	rear=temp;
}

int deleteq()
{ 
	int a;
	nodepointer temp=front;
	a=temp->vertex;
	front=temp->link;
	free(temp);
	return a;
}

void BFS(int v)
{
    nodepointer p;
	printf("\n%5d",v);
    visited[v]=TRUE;
	addq(v);
	while(front)
	{
		v=deleteq();
		for(p=G[v];p; p=p->link)
    	{
       	   if(!visited[p->vertex])
			{
				printf("%5d",p->vertex);
            	addq(p->vertex); 
				visited[p->vertex] = TRUE;
			}
   		}
	}
	printf("\n");
}
 
void insert(int vi,int vj)
{
    nodepointer p,q;
    q=(nodepointer)malloc(sizeof(node));
    q->vertex=vj;
    q->link=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {   for(p=G[vi];p->link!=NULL; p=p->link);
        p->link=q;
    }
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices:");
   	scanf("%d",&n);
 
	for(i=0;i<n;i++)
        G[i]=NULL;
    printf("Enter number of edges \n");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(u,v):");
		scanf("%d%d",&vi,&vj);
		if(i==0)
		{
			x=vi;
		}
		insert(vi,vj);
    }
}
 
int main()
{
    int i;
	front = rear= NULL;
    read_graph();
   	for(i=0;i<n;i++)
        visited[i]=FALSE;
	printf("\n\nNodes visited in BFS order\n");
    BFS(x);
	return 0;
}
