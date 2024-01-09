#include <stdio.h>

void solution(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = maxi > arr[i] ? maxi : arr[i];
    }
    int hash[maxi + 1];
    for (int i = 0; i <= maxi; i++)
    {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i <= maxi; i++)
    {
        if (hash[i] > 1)
            count++;
    }
    int maxi2 = hash[0];
    int maxel = 0;
    for (int i = 0; i <= maxi; i++)
    {
        if (hash[i] > maxi2)
        {
            maxi2 = hash[i];
            maxel = i;
        }
    }
    printf("Number of duplicate elements: %d\n", count);
    printf("Most repeated element = %d", maxel);
}

int main()
{
    int n;
    FILE *fp;
    fp = fopen("./lab1data.dat", "r");
    if (fp == NULL)
    {
        printf("File not found!");
        return 1;
    }
    fscanf(fp, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    solution(arr, n);
    printf("\nVatsal Saxena, 21051698, CSE-27");
    return 0;
}
