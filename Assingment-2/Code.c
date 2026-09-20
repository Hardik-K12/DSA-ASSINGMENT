#include <stdio.h>

// Recursive function for Binary Search
int binarySearch(int arr[], int low, int high, int target)
{
    // Element not found
    if(low > high)
        return -1;

    // Find middle index
    int mid = (low + high) / 2;

    // Check if middle element is target
    if(arr[mid] == target)
        return mid;

    // Search in left half
    if(arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target);

    // Search in right half
    return binarySearch(arr, mid + 1, high, target);
}

int main()
{
    int n, target, result;

    // Take size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take sorted array elements
    printf("Enter %d sorted elements:\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Take element to search
    printf("Enter element to search: ");
    scanf("%d", &target);

    // Call binary search function
    result = binarySearch(arr, 0, n - 1, target);

    // Display result
    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
