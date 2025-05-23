#include <stdio.h>
#include <stdlib.h>
 
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void linkedlistTraversal(struct Node* ptr)
{
    while(ptr!= NULL){
        printf("[%d]", ptr->data);
        if(ptr->next!= NULL)
        printf("->");
        ptr = ptr->next;
    }
    printf("->NULL\n");
}
struct Node* insertAtFirst(struct Node*head , int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct Node* insertAtIndex(struct Node* head , int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i!= index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data= data;
    ptr->next= p->next;
    p->next= ptr;
    return head;
}
struct Node* insertAtEnd(struct Node* head , int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data= data;
    ptr->next = NULL;
    return head;
}
struct Node* insertAfterNode(struct Node* head , struct Node* prevNode , int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}
struct Node* deleteAtFirst(struct Node* head){
    struct Node*ptr = head;
    head = head-> next;
    free(ptr);
        return head;
    }
    struct Node* deleteAtIndex(struct Node* head, int index){
        struct Node* p = head;
        struct Node* q = head->next;
        for(int i=0; i<index-1; i++){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return head;
    }
    struct Node* deleteAtEnd(struct Node* head){
        struct Node* p = head;
        struct Node* q = head->next;
        while(q->next != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        return head;
    }
    struct Node* deleteAtValue(struct Node* head, int value){
        struct Node* p = head;
        struct Node* q = head->next;
        while(q->data != value && q->next != NULL){
            p = p->next;
            q = q->next;
        }
        if(q->data == value){
            p->next = q->next;
            free(q);
        }
        return head;
    }
int main()
{
    struct Node* head = createNode(2);
    struct Node* second = createNode(4);
    struct Node* third = createNode(6);
    struct Node* fourth = createNode(8);
    
    
    head->next = second;
    second->next = third;
    third->next = fourth;
   
    printf("linked list before insertion\n");
    linkedlistTraversal(head);
    //head = insertAtFirst(head, 1);
    head = insertAtIndex(head, 24,3);
   // head = insertAtEnd(head, 10);
    //head = insertAfterNode(head, second, 5);
    printf("linked list after insertion\n");
    linkedlistTraversal(head);
    printf("linked list before deletion\n");
    linkedlistTraversal(head);
   // head = deleteAtFirst(head);
     head = deleteAtIndex(head,3);
    //head = deleteAtEnd(head);
   // head = deleteAtValue(head, 6);
    
   
    printf("linked list after deletion\n");
    linkedlistTraversal(head);
   

    free(head);
    free(second);
    free(third);
    free(fourth);
    
    return 0;
}
