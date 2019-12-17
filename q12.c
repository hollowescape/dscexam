#include<stdio.h>
#include<stdlib.h>

typedef struct node *tree_p;
typedef struct node{
	int data;
	tree_p llink;
	tree_p rlink;
	}l;

	 tree_p search(tree_p root,int key)
	{
		if(!root)
		return NULL;
		if(key == root->data)
		return root;
		if(key > root->data)
		return search(root->rlink,key);
		if(key < root->data)
		return search(root->llink,key);
	}
	tree_p createNode(int value)
{
        tree_p newNode = (tree_p)malloc(sizeof(l));
        newNode->data = value;
        newNode->llink = NULL;
        newNode->rlink = NULL;
        return newNode;
}
      
      
tree_p insert(tree_p root, int data)
    {
        if (root == NULL) return createNode(data);
        if (data < root->data)
            root->llink  = insert(root->llink, data);
        else if (data > root->data)
            root->rlink = insert(root->rlink, data);   
     
        return root;
    }
    
	void display(tree_p root)
	{
		if(root){
	
		display(root->llink);
		printf("%d\n",root->data);
		display(root->rlink);
		}
	}
	
	void main()
	{
		int n,key, keys,e=1;
		tree_p root =(tree_p)malloc(sizeof(l));
		tree_p rec;
		while(e==1){
		printf(" enter the choice\n");
		printf(" 1. insert\n 2. search\n 3.display\n 4. exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf(" enter the element to be inserted\n");
				scanf("%d",&key);
				insert(root,key);
				break;
			case 2: printf(" enter the element to be searched\n");
				scanf("%d",&keys);
				rec=search(root,keys);
				if(rec==NULL)
				printf(" no element found\n");
				else
				printf(" element found \n");
				break;
			case 3: printf(" inorder display\n");
				display(root);
				break;
			case 4: exit(0);
				break;
		
		}				
			}
	}