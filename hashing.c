#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

// Initialize the hash table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// Hash function: h(k) = (a*k + b) % SIZE
int hash(int key, int a, int b) {
    return (a * key + b) % SIZE;
}

// Secondary hash for rehashing
int h2(int key) {
    return 7 - (key % 7);  // Must not be 0
}

// Linear Probing
void insertLinear(int key, int a, int b) {
    int index = hash(key, a, b);
    int i = 0;
    while (table[(index + i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i < SIZE)
        table[(index + i) % SIZE] = key;
    else
        printf("Table Full! Could not insert %d\n", key);
}

// Rehashing
void insertRehash(int key, int a, int b) {
    int index = hash(key, a, b);
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
void insertQuadratic(int key, int a, int b) {
    int index = hash(key, a, b);
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
    int n, choice, a, b;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    int keys[n];
    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter hash function parameters for h(k) = (a*k + b) %% 10\n");
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    printf("\nChoose Collision Resolution Technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Rehashing\n");
    printf("3. Quadratic Probing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    initialize();

    for (int i = 0; i < n; i++) {
        if (choice == 1)
            insertLinear(keys[i], a, b);
        else if (choice == 2)
            insertRehash(keys[i], a, b);
        else if (choice == 3)
            insertQuadratic(keys[i], a, b);
        else {
            printf("Invalid choice!\n");
            return 1;
        }
    }

    display();

    return 0;
}
