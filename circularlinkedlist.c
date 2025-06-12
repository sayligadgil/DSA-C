#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Create and return a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Traverse and display the circular linked list
void linkedListTraversal(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *ptr = head;
    do {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != head) {
            printf(" -> ");
        }
    } while (ptr != head);
    printf("\n");
}
// Insert at the end of the CLL
void insertAtEnd(struct Node** head, int data) {
    struct Node* ptr = createNode(data);

    if (*head == NULL) {
        ptr->next = ptr;
        *head = ptr;
    } else {
        struct Node* p = *head;
        while (p->next != *head)
            p = p->next;

        p->next = ptr;
        ptr->next = *head;
    }
}

// Insert at the beginning of the CLL
void insertAtBeginning(struct Node** head, int data) {
    struct Node* ptr = createNode(data);

    if (*head == NULL) {
        ptr->next = ptr;
        *head = ptr;
    } else {
        struct Node* p = *head;
        while (p->next != *head)
            p = p->next;

        p->next = ptr;
        ptr->next = *head;
        *head = ptr;
        
    }
}

// Insert after a specific value in CLL
void insertAfter(struct Node* head, int key, int data) {
    if (head == NULL) return;

    struct Node* p = head;
    do {
        if (p->data == key) {
            struct Node* ptr = createNode(data);
            ptr->next = p->next;
            p->next = ptr;
            return;
        }
        p = p->next;
    } while (p != head);

    printf("Value %d not found in the list.\n", key);
}
// Delete node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr = *head;

    // If only one node
    if (ptr->next == *head) {
        free(ptr);
        *head = NULL;
        return;
    }

    struct Node* p = *head;
    while (p->next != *head)
        p = p->next;

    p->next = (*head)->next;
    *head = (*head)->next;
    free(ptr);
}

// Delete node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr = *head;

    // If only one node
    if (ptr->next == *head) {
        free(ptr);
        *head = NULL;
        return;
    }

    struct Node* p = *head;
    while (p->next->next != *head)
        p = p->next;

    ptr = p->next;
    p->next = *head;
    free(ptr);
}

// Delete node by value
void deleteByValue(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr = *head;
    struct Node* p = *head;

    // Case 1: only one node
    if (ptr->data == key && ptr->next == *head) {
        free(ptr);
        *head = NULL;
        return;
    }

    // Case 2: head node is to be deleted
    if ((*head)->data == key) {
        while (p->next != *head)
            p = p->next;

        p->next = (*head)->next;
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
        return;
    }

    // Case 3: key in middle or end
    while (p->next != *head && p->next->data != key)
        p = p->next;

    if (p->next->data == key) {
        ptr = p->next;
        p->next = ptr->next;
        free(ptr);
    } else {
        printf("Value %d not found in the list.\n", key);
    }
}
int search(struct Node* head, int key) {
    if (head == NULL) {
        return -1; // List is empty
    }

    struct Node* p = head;
    int index = 0;

    do {
        if (p->data == key) {
            return index; // Found, return index
        }
        p = p->next;
        index++;
    } while (p != head);

    return -1; // Not found
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Initial list:\n");
    linkedListTraversal(head);

    insertAtBeginning(&head, 5);
    printf("After inserting 5 at beginning:\n");
    linkedListTraversal(head);

    insertAtEnd(&head, 40);
    printf("After inserting 40 at end:\n");
    linkedListTraversal(head);

    insertAfter(head, 20, 25);
    printf("After inserting 25 after 20:\n");
    linkedListTraversal(head);

    deleteFromBeginning(&head);
    printf("After deleting from beginning:\n");
    linkedListTraversal(head);
    
    deleteFromEnd(&head);
    printf("After deleting from end:\n");
    linkedListTraversal(head);
    
    deleteByValue(&head, 25);
    printf("After deleting 25 by value:\n"); 
    linkedListTraversal(head);
   
    int idx = search(head, 20);
if (idx != -1)
    printf("Element 25 found at index: %d\n", idx);
else
    printf("Element 25 not found in the list.\n");

    return 0;
}