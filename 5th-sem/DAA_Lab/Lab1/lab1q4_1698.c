#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2, int p) // p1 points to the first element of the array, p2 is size of array
{

    for (int j = 0; j < p; j++) // loop till value p
    {
        int temp = *(p1 + p2 - 1); // temp points to the last element

        for (int i = p2 - 1; i > 0; i--)
        {
            EXCHANGE((p1 + i), (p1 + i - 1)); // exchanges last and second last element of the array
        }

        *p1 = temp;
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
    fclose(fp);

    int p;
    printf("Enter p: ");
    scanf("%d", &p);
    ROTATE_RIGHT(arr_8, n_8, p);

    printf("Rotated Array: ");
    for (int i = 0; i < n_8; i++)
    {
        printf("%d ", arr_8[i]);
    }
    printf("\nVatsal Saxena, 21051698, CSE-27");
    return 0;
}
