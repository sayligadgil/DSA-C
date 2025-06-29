#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];
int linearCount = 0, quadraticCount = 0;

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize tables
void initializeTables() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        linearTable[i] = EMPTY;
        quadraticTable[i] = EMPTY;
    }
}

// Insert using linear probing
void insertLinear(int key) {
    if (linearCount >= TABLE_SIZE) {
        printf("Hash table is full (Linear Probing)\n");
        return;
    }
    int h = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i) % TABLE_SIZE;
        if (linearTable[idx] == EMPTY || linearTable[idx] == DELETED) {
            linearTable[idx] = key;
            linearCount++;
            printf("Inserted %d at index %d (Linear)\n", key, idx);
            return;
        }
    }
    printf("Could not insert %d (Linear)\n", key);
}

// Insert using quadratic probing
void insertQuadratic(int key) {
    if (quadraticCount >= TABLE_SIZE) {
        printf("Hash table is full (Quadratic Probing)\n");
        return;
    }
    int h = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i * i) % TABLE_SIZE;
        if (quadraticTable[idx] == EMPTY || quadraticTable[idx] == DELETED) {
            quadraticTable[idx] = key;
            quadraticCount++;
            printf("Inserted %d at index %d (Quadratic)\n", key, idx);
            return;
        }
    }
    printf("Could not insert %d (Quadratic)\n", key);
}

// Search key in linear probing
int searchLinear(int key) {
    int h = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i) % TABLE_SIZE;
        if (linearTable[idx] == EMPTY)
            return -1;
        if (linearTable[idx] == key)
            return idx;
    }
    return -1;
}

// Search key in quadratic probing
int searchQuadratic(int key) {
    int h = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i * i) % TABLE_SIZE;
        if (quadraticTable[idx] == EMPTY)
            return -1;
        if (quadraticTable[idx] == key)
            return idx;
    }
    return -1;
}

// Delete key in linear probing
void deleteLinear(int key) {
    int idx = searchLinear(key);
    if (idx != -1) {
        linearTable[idx] = DELETED;
        linearCount--;
        printf("Deleted %d from index %d (Linear)\n", key, idx);
    } else {
        printf("Key %d not found (Linear)\n", key);
    }
}

// Delete key in quadratic probing
void deleteQuadratic(int key) {
    int idx = searchQuadratic(key);
    if (idx != -1) {
        quadraticTable[idx] = DELETED;
        quadraticCount--;
        printf("Deleted %d from index %d (Quadratic)\n", key, idx);
    } else {
        printf("Key %d not found (Quadratic)\n", key);
    }
}

// Display hash table
void displayTable(int *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (table[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main() {
    int choice, method, key;

    initializeTables();

    while (1) {
        printf("\n---- Hashing Menu ----\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display Table\n5. Show Size\n6. Exit\n");
        printf("Choose operation: ");
        scanf("%d", &choice);

        if (choice == 6) break;

        if (choice >= 1 && choice <= 3) {
            printf("Enter key: ");
            scanf("%d", &key);
        }

        if (choice != 4 && choice != 5) {
            printf("Choose method: 1. Linear Probing  2. Quadratic Probing: ");
            scanf("%d", &method);
        }

        switch (choice) {
            case 1:
                if (method == 1)
                    insertLinear(key);
                else
                    insertQuadratic(key);
                break;
            case 2:
                if (method == 1) {
                    int idx = searchLinear(key);
                    if (idx != -1) printf("Found at index %d (Linear)\n", idx);
                    else printf("Not found (Linear)\n");
                } else {
                    int idx = searchQuadratic(key);
                    if (idx != -1) printf("Found at index %d (Quadratic)\n", idx);
                    else printf("Not found (Quadratic)\n");
                }
                break;
            case 3:
                if (method == 1)
                    deleteLinear(key);
                else
                    deleteQuadratic(key);
                break;
            case 4:
                printf("Choose method to display: 1. Linear Probing  2. Quadratic Probing: ");
                scanf("%d", &method);
                if (method == 1)
                    displayTable(linearTable);
                else
                    displayTable(quadraticTable);
                break;
            case 5:
                printf("Linear Table Size: %d\n", linearCount);
                printf("Quadratic Table Size: %d\n", quadraticCount);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
