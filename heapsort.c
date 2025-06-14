#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

void heapSortAscending(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 -1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call maxHeapify on reduced heap
        maxHeapify(arr, i, 0);
    }
}

void heapSortDescending(int arr[], int n) {
    // Build min heap
    for (int i = n / 2 -1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (min) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call minHeapify on reduced heap
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Choose sorting order:\n");
    printf("1. Ascending (Heap Sort using Max Heap)\n");
    printf("2. Descending (Heap Sort using Min Heap)\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        heapSortAscending(arr, n);
        printf("Sorted array in ascending order:\n");
    } else if (choice == 2) {
        heapSortDescending(arr, n);
        printf("Sorted array in descending order:\n");
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printArray(arr, n);

    return 0;
}
