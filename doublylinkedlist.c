#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev,*next;
};
//create an alias name
typedef struct node dnode;
//referencing to head pointer
dnode*head=NULL;
//create node
void createDoublelist(int x)
{
	dnode*tempNode=NULL;
	tempNode=(dnode*)malloc(sizeof(dnode));
	tempNode->data=x;
	tempNode->next=tempNode->prev=NULL;
	head=tempNode;
	return;
}
int main() {
    // Test the function
    createDoublelist(10);
    if (head != NULL) {
        printf("Node created with data: %d\n", head->data);
    } else {
        printf("Node creation failed.\n");
    }
    return 0;
}
