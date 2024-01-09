#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n, long long *comparisons)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (arr[j] > current && j >= 0)
        {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--; // first step , pointing to arr[-1]
        }
        arr[j + 1] = current; // arr[-1+1]=arr[0]
    }
}

// Function to read data from a file
int readFromFile(char *filename, int arr[])
{
    FILE *fp = fopen(filename, "r");
    int count = 0;
    while (fscanf(fp, "%d", &arr[count]) == 1) // fscanf returns 1 after succesfully reading and assigning an integer
    {
        count++;
    }

    fclose(fp);
    return count;
}

int main()
{
    int choice;
    long long comparisons = 0;

    while (1)
    {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            break;
        }

        int arr[500];
        int n;

        switch (choice)
        {
        case 1:
            n = readFromFile("asc.dat", arr);
            break;
        case 2:
            n = readFromFile("des.dat", arr);
            break;
        case 3:
            n = readFromFile("ran.dat", arr);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            continue;
        }

        /*        printf("Before Sorting:\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
        */
        insertionSort(arr, n, &comparisons);

        printf("After Sorting:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Number of Comparisons: %lld\n", comparisons);
    }
    return 0;
}
