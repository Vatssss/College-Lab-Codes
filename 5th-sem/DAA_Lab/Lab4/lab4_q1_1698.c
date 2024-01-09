#include <stdio.h>

int count = 0;

void merge(int arr[], int start, int mid, int end) // Conquer
{
    int size = end - start + 1;
    int merged[size];

    int index1 = start;
    int index2 = mid + 1;
    int x = 0; // Index of the new merged array

    while (index1 <= mid && index2 <= end)
    {
        if (arr[index1] <= arr[index2])
        {
            merged[x] = arr[index1];
            x++;
            index1++;
        }
        else
        {
            merged[x] = arr[index2];
            x++;
            index2++;
        }
        count++;
    }

    while (index1 <= mid)
    {
        merged[x] = arr[index1];
        x++;
        index1++;
    }

    while (index2 <= end)
    {
        merged[x] = arr[index2];
        x++;
        index2++;
    }

    for (int i = 0, j = start; i < size; i++, j++)
    {
        arr[j] = merged[i];
    }
}

void mergeSort(int arr[], int start, int end) // Divide
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void displayFileContent(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    int num;
    printf("Content of the file %s:\n", filename);
    while (fscanf(file, "%d", &num) == 1)
    {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

int main()
{
    int choice;

    printf("\nMAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        displayFileContent("inAsc.dat");
        {
            FILE *ip = fopen("inAsc.dat", "r");
            int n;
            fscanf(ip, "%d", &n);
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(ip, "%d", &arr[i]);
            }

            fclose(ip);

            mergeSort(arr, 0, n - 1);

            FILE *op = fopen("outAsc.dat", "w");
            for (int i = 0; i < n; i++)
            {
                fprintf(op, "%d ", arr[i]);
            }

            fclose(op);

            printf("After Sorting: Content of the output file\n");
            displayFileContent("outAsc.dat");
            printf("Number of comparisons = %d\n", count);
        }
        break;

    case 2:
        displayFileContent("inDesc.dat");
        {
            FILE *ip = fopen("inDesc.dat", "r");

            int n;
            fscanf(ip, "%d", &n);
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(ip, "%d", &arr[i]);
            }

            fclose(ip);

            mergeSort(arr, 0, n - 1);

            FILE *op = fopen("outDesc.dat", "w");

            for (int i = 0; i < n; i++)
            {
                fprintf(op, "%d ", arr[i]);
            }

            fclose(op);

            printf("After Sorting: Content of the output file\n");
            displayFileContent("outDesc.dat");
            printf("Number of comparisons = %d\n", count);
        }
        break;

    case 3:
        displayFileContent("inRand.dat");
        {
            FILE *ip = fopen("inRand.dat", "r");

            int n;
            fscanf(ip, "%d", &n);
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(ip, "%d", &arr[i]);
            }

            fclose(ip);

            mergeSort(arr, 0, n - 1);

            FILE *op = fopen("outRand.dat", "w");

            for (int i = 0; i < n; i++)
            {
                fprintf(op, "%d ", arr[i]);
            }

            fclose(op);

            printf("After Sorting: Content of the output file\n");
            displayFileContent("outRand.dat");
            printf("Number of comparisons = %d\n", count);
        }
        break;

    case 4:
        printf("Exiting...\n");
        break;

    default:
        printf("Invalid choice\n");
    }

    return 0;
}
