#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

// Hash function: h(k) = (2k + 3) % SIZE
int hashFunction(int key) {
    return (2 * key + 3) % SIZE;
}

// Second hash function for double hashing
int secondHash(int key) {
    return 7 - (key % 7); // Must be less than SIZE and non-zero
}

// Initialize the hash table
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d --> [ ]\n", i);
        else
            printf("%d --> %d\n", i, hashTable[i]);
    }
}

// Linear Probing
void insertLinear(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i < SIZE)
        hashTable[(index + i) % SIZE] = key;
    else
        printf("Hash table overflow (Linear) for key %d\n", key);
}

// Quadratic Probing
void insertQuadratic(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i * i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i < SIZE)
        hashTable[(index + i * i) % SIZE] = key;
    else
        printf("Hash table overflow (Quadratic) for key %d\n", key);
}

// Double Hashing 
void insertDoubleHash(int key) {
    int index1 = hashFunction(key);
    int stepSize = secondHash(key);
    int i = 0;

    while (hashTable[(index1 + i * stepSize) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i < SIZE)
        hashTable[(index1 + i * stepSize) % SIZE] = key;
    else
        printf("Hash table overflow (Double Hashing) for key %d\n", key);
}

int main() {
    int n, key, choice;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    int keys[n];
    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("\nChoose Collision Resolution Technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing (Rehashing)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    initialize();

    for (int i = 0; i < n; i++) {
        if (choice == 1)
            insertLinear(keys[i]);
        else if (choice == 2)
            insertQuadratic(keys[i]);
        else if (choice == 3)
            insertDoubleHash(keys[i]);
        else {
            printf("Invalid choice.\n");
            return 1;
        }
    }

    display();
    return 0;

}
