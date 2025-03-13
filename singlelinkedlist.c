#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
typedef struct node snode;
snode*head=NULL;
void create(int x)
{
	snode*temp=NULL;
	head=(snode*)malloc(sizeof(snode));
	head->data=x;
	head->next=NULL;
}//create list
void printlist()
{
snode* temp=head;
while(temp!=NULL)
{
	printf("%d->",temp->data);
	temp=temp->next;
}
printf("NULL\n");
}

int main()
{
	create(10);
	printlist();
	return 0;
}
