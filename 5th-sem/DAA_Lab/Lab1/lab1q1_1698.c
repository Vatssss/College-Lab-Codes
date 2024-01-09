#include <stdio.h>
#include <limits.h>
int secondLargest(int arr_8[], int n_8)
{
    if (n_8 < 2)
        return -1;
    int large_8 = INT_MIN, slarge_8 = INT_MIN;
    int i_8;
    for (i_8 = 0; i_8 < n_8; i_8++)
    {
        if (arr_8[i_8] > large_8)
        {
            slarge_8 = large_8;
            large_8 = arr_8[i_8];
        }

        else if (arr_8[i_8] > slarge_8 && arr_8[i_8] < large_8)
        {
            slarge_8 = arr_8[i_8];
        }
    }
    return slarge_8;
}
int secondSmallest(int arr_8[], int n_8)
{
    if (n_8 < 2)
        return -1;
    int small_8 = INT_MAX;
    int ssmall_8 = INT_MAX;
    int i_8;
    for (i_8 = 0; i_8 < n_8; i_8++)
    {
        if (arr_8[i_8] < small_8)
        {
            ssmall_8 = small_8;
            small_8 = arr_8[i_8];
        }
        else if (arr_8[i_8] < ssmall_8 && arr_8[i_8] > small_8)
        {
            ssmall_8 = arr_8[i_8];
        }
    }
    return ssmall_8;
}
int main()
{
    int n_8;
    FILE *fp;
    fp = fopen("./lab1data.dat", "r");
    fscanf(fp, "%d", &n_8);
    int arr_8[n_8];
    for (int i_8 = 0; i_8 < n_8; i_8++)
    {
        fscanf(fp, "%d", &arr_8[i_8]);
    }
    int slarge_8 = secondLargest(arr_8, n_8);
    int ssmall_8 = secondSmallest(arr_8, n_8);
    printf("Second largest = %d\n", slarge_8);
    printf("Second smallest = %d\n", ssmall_8);
    printf("Vatsal Saxena, 21051698, CSE-27");
    return 0;
}