#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// Simple hash function: h(k) = k % SIZE
int hash(int key) {
    return key % SIZE;
}

// Secondary hash for rehashing
int h2(int key) {
    return 7 - (key % 7);  // Should not be 0
}

// Linear Probing
void insertLinear(int key) {
    int index = hash(key);
    int i = 0;
    while (table[(index + i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i < SIZE)
        table[(index + i) % SIZE] = key;
    else
        printf("Table Full! Could not insert %d\n", key);
}

// Rehashing
void insertRehash(int key) {
    int index = hash(key);
    int step = h2(key);
    if (step == 0) step = 1;
    int i = 0;
    while (table[(index + i * step) % SIZE] != -1 && i < SIZE)
        i++;
    if (i < SIZE)
        table[(index + i * step) % SIZE] = key;
    else
        printf("Table Full! Could not insert %d\n", key);
}

// Quadratic Probing
void insertQuadratic(int key) {
    int index = hash(key);
    int i = 0;
    while (table[(index + i * i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i < SIZE)
        table[(index + i * i) % SIZE] = key;
    else
        printf("Table Full! Could not insert %d\n", key);
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main() {
    int n, choice;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    int keys[n];
    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("\nChoose Collision Resolution Technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Rehashing\n");
    printf("3. Quadratic Probing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    initialize();

    for (int i = 0; i < n; i++) {
        if (choice == 1)
            insertLinear(keys[i]);
        else if (choice == 2)
            insertRehash(keys[i]);
        else if (choice == 3)
            insertQuadratic(keys[i]);
        else {
            printf("Invalid choice!\n");
            return 1;
        }
    }

    display();

    return 0;
}
