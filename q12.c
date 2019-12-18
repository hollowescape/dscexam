#include<stdio.h>
#include<stdlib.h>

typedef struct node *tree;
typedef struct node
{
	tree lc;
	tree rc;
	int data;
}l;
tree root,rec;
tree search(tree root,int key)
{
	if(!root)
	return NULL;
	if(key==root->data)
	return root;
	if(key>root->data)
	return search(root->rc,key);
	if(key < root->data)
	return search(root->lc,key);
}

tree createnode(int num)
{
	tree t=(tree)malloc(sizeof(l));
	t->data=num;
	t->lc=NULL;
	t->rc=NULL;
	return t;
}

tree insert(tree root,int key)
{
	if(root ==NULL) return createnode(key);
	if(key>root->data)
	root->rc=insert(root->rc,key);
	else if(key<root->data)
	root->lc=insert(root->lc,key);
	else
	return root;
}

void inorder(tree root)
{
	if(root)
	{
	inorder(root->lc);
	printf("%d\n",root->data);
	inorder(root->rc);
	}
}

void main()
{
	int n,key,o;
	while(1)
	{
		printf("enter the choice\n");
		printf("1. insert\n 2.search\n 3.disply\n 4.exit");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter the element to be inserted\n");
				   scanf("%d",&key);
				   root=insert(root,key);
				   break;
		    case 2: printf("enter the element to bes ezr\n");
		    		scanf("%d",&o);
		    		rec=search(root,o);
		    		if(rec)
		    		{
		    			printf("element found\n");
		    		}
		    		else
		    		{
		    			printf("element not found\n");
		    		}
		    		break;
		    case 3:inorder(root);
		    		break;
		    case 4: exit(0);
		    		break;
		}
	}
}