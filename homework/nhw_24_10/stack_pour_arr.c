#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000005
typedef struct node
{
	int val;
	struct node* next;
} node;
int stk[MAXN],top;
node* init(int val)
{
	node* p=(node*)malloc(sizeof(node));
	p->val=val;
	p->next=NULL;
	return p;
}
void update(node** from, node** to)
{
	node* p=*from;
	while(p!=NULL)
	{
		node* next=p->next;
		p->next=*to;
		*to=p;
		p=next;
	}
	*from=NULL;
}
void print(node* stack)
{
	node* p=stack;
	top=0;
	while(p)
	{
		stk[top++]=p->val;
		p=p->next;
	}
	if(top==0)
		printf("0");
	while(top)
		printf("%d ",stk[--top]);
	printf("\n");
}
int read()
{
    int res = 0;
    scanf("%d", &res);
	return res;
}
int n,m;
int main()
{
	n=read(),m=read();
	node** stacks=(node**)malloc(MAXN*sizeof(node*));
	for(int i=1;i<=n;i++)
		stacks[i]=init(i);
	int x,y;
	while(m--)
	{
		x=read(),y=read();
		update(&stacks[x],&stacks[y]);
	}
	for(int i=1;i<=n;i++)
		print(stacks[i]);
	return 0;
}