#include <stdio.h>

void prefixSum(int arr_8[], int n_8)
{
    int psum_8[n_8];
    psum_8[0] = arr_8[0];
    for (int i_8 = 1; i_8 < n_8; i_8++)
    {
        psum_8[i_8] = psum_8[i_8 - 1] + arr_8[i_8];
    }
    printf("Prefix sum array: \n");
    for (int i_8 = 0; i_8 < n_8; i_8++)
    {
        printf("%d ", psum_8[i_8]);
    }
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
    prefixSum(arr_8, n_8);
    printf("\nVatsal Saxena, 21051698, CSE-27");
    return 0;
}