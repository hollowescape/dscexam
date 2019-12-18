#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodePtr;
typedef struct node {
     nodePtr llink;
     int data;
     nodePtr rlink;
}node;

nodePtr head;

void dinsert() 
{
    int n;
    nodePtr temp;
    printf("Enter the info for the new node");
    scanf("%d", &n);
    temp=(nodePtr)malloc(sizeof(node));
    temp->data=n;
    head->llink->rlink = temp;
    temp->llink = head->llink; 
    temp->rlink = head; 
    head->llink = temp;
//    head->rlink-> llink = temp; 
//    head->rlink = temp;
}

void ddelete()
{
	nodePtr temp=head->rlink;
	if (head->rlink == head)
		printf("Deletion of head node not permitted.\n");
	else 
	{ 
		head->rlink = temp->rlink;
		temp->rlink->llink = head;
		printf("removing node with data %d\n",temp->data);
		free(temp);
    }
}

void displayfront()
{
	nodePtr temp;
	if (head->rlink == head)
		printf("Empty list.\n");
	else 
	{ 
		for(temp=head->rlink; temp->rlink != head; temp = temp->rlink)
			printf("%d\t", temp->data);
		printf("%d\t", temp->data);
		printf("\n\n");
	}
}

void displayreverse()
{
	nodePtr temp;
	if (head->rlink == head)
		printf("Empty list.\n");
	else 
	{ 
		for(temp=head->llink; temp->llink != head; temp = temp->llink)
			printf("%d\t", temp->data);
		printf("%d\t", temp->data);
		printf("\n\n");
	}
}

int main()
{
	unsigned int choice;
	head=(nodePtr)malloc(sizeof(node));
	head->rlink=head;
	head->llink=head;
	
	while(1)
	{
		printf("1:insert a node in DLL \n2:delete a node from DLL \n3:display the DLL\n4:display reverse\n 5.exit");
		scanf("%u", &choice);
		switch(choice)
		{
			case 1: dinsert();
					break;
			case 2: ddelete();
					break;
			case 3: displayfront();
					break;
			case 4: displayreverse();
					break;
			case 5: exit(0);
					break;
			default: printf("Invalid choice... try again\n");
		}
	}
	return 0;
}