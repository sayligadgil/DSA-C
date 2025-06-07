#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[100], size, key, i;

    // Taking size of array
    printf("Enter number of elements (sorted in ascending order): ");
    scanf("%d", &size);

    // Taking array input
    printf("Enter %d sorted elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the key to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Performing binary search
    int result = binarySearch(arr, size, key);

    // Displaying result
    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
