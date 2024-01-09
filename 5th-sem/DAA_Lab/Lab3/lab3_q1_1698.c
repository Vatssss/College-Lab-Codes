#include <stdio.h>

int binarySearch(int arr[], int size, int key, int *count)
{
    int start = 0;
    int end = size - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            end = mid - 1; // updates value of end, else infinite loop
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        (*count)++;
    }
    return result;
}
int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int count = 0;
    int position = binarySearch(arr, size, key, &count);

    if (position != -1)
    {
        printf("%d found at index position %d\n", key, position);
        printf("Number of comparisons: %d\n", count);
    }
    else
    {
        printf("%d not found in the array\n", key);
        printf("Number of comparisons: %d\n", count);
    }

    return 0;
}
