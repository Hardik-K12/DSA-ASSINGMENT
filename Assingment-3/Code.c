#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bs(int arr[], int n)
{
    // Compare adjacent elements
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in wrong order
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }

    printf("Sorted array using Bubble Sort: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Selection Sort
void ss(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        // Assume current element is minimum
        int min = i;

        // Find minimum element
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        // Put minimum element at correct position
        swap(&arr[i], &arr[min]);
    }

    printf("Sorted array using Selection Sort: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Insertion Sort
void is(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        // Store current element
        int key = arr[i];
        int j = i - 1;

        // Move bigger elements one position ahead
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }

    printf("Sorted array using Insertion Sort: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    // Taking last element as pivot
    int pivot = arr[high];
    int i = low - 1;

    // Compare elements with pivot
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Put pivot at correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort
void qs(int arr[], int low, int high)
{
    if(low < high)
    {
        // Find pivot position
        int pi = partition(arr, low, high);

        // Sort left and right parts
        qs(arr, low, pi - 1);
        qs(arr, pi + 1, high);
    }
}

// Merge two sorted parts
void merge(int arr[], int low, int mid, int high, int temp[])
{
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare elements from both parts
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left part
    while(i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right part
    while(j <= high)
        temp[k++] = arr[j++];

    // Copy sorted elements back to original array
    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

// Merge Sort
void ms(int arr[], int low, int high, int temp[])
{
    if(low < high)
    {
        // Find middle position
        int mid = (low + high) / 2;

        // Divide array into two parts
        ms(arr, low, mid, temp);
        ms(arr, mid + 1, high, temp);

        // Merge the sorted parts
        merge(arr, low, mid, high, temp);
    }
}

int main()
{
    int n, choice;

    // Taking number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    // Taking array elements
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Display sorting methods
    printf("\nChoose method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");

    // Taking user's choice
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Perform sorting according to choice
    switch(choice)
    {
        case 1:
            bs(arr, n);
            break;

        case 2:
            ss(arr, n);
            break;

        case 3:
            is(arr, n);
            break;

        case 4:
            qs(arr, 0, n - 1);

            printf("Sorted array using Quick Sort: ");
            for(int i = 0; i < n; i++)
                printf("%d ", arr[i]);

            printf("\n");
            break;

        case 5:
            ms(arr, 0, n - 1, temp);

            printf("Sorted array using Merge Sort: ");
            for(int i = 0; i < n; i++)
                printf("%d ", arr[i]);

            printf("\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
