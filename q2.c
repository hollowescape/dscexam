#include<stdio.h>
#define max 100

typedef struct 
{
	int row;
	int col;
	int val;

}terms;
terms a[max],b[max];
void fasttranspose(terms a[],terms b[]);
void print(terms a[]);
void main()
{
	int i,r,c,k=1,j,value;
	printf(" enter the number of row and coloum\n");
	scanf("%d%d",&r,&c);
	a[0].row=r;
	a[0].col=c;
	printf(" enter the elements of matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&value);
			if(value!=0)
			{
				a[k].row=i;
				a[k].col=j;
				a[k].val=value;
				k++;
			}
		}
	}
	a[0].val=k-1;
	fasttranspose(a,b);
	print(a);
	printf("\n the transpose of matrix is \n");
	print(b);
}
void fasttranspose(terms a[],terms b[])
{
	int n,i,j;
	int rowterms[a[0].col], startpos[a[0].col],numterms=a[0].val,numcoloum=a[0].col;
	 b[0].row=a[0].col;
        b[0].col=a[0].row;
        b[0].val=a[0].val;

	for(i=0;i<numcoloum;i++)
	{
		rowterms[i]=0;
	}
	for(j=0;j<numterms;j++)
		rowterms[a[j].col]++;
		startpos[0]=1;
	
	for(j=1;j<numcoloum;j++)
	{
		startpos[j]=startpos[j-1]+rowterms[j-1];
	}
	for(i=1;i<=numterms;i++)
	{	
		j=startpos[a[i].col]++;
		b[j].col=a[i].row;
		b[j].row=a[i].col;
		b[j].val=a[i].val;

	}
}
void print(terms a[])
{
	int r,c,k=1,i,j;
	r=a[0].row;
	c=a[0].col;
	for(i=0;i<r;i++)
	{	printf("\n");
		for(j=0;j<c;j++)
		{
			if((a[k].row==i)&&(a[k].col==j))
			{
				printf(" %d",a[k].val);
				k++;
			}
			else
			{
				printf("0");
			}
		}
	}
}                             