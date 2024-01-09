// Write a C program to swap the content of 2 variables entered through the command line using function and pointer.
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int num1, num2;
    printf("Enter first number: \n");
    scanf("%d", &num1);
    printf("Enter second number: \n");
    scanf("%d", &num2);

    printf("Before swapping the numbers: \n");
    printf("%d %d \n", num1, num2);

    swap(&num1, &num2);
    // passing the addresses of the numbers

    printf("After swapping the numbers: \n");
    printf("%d %d", num1, num2);
}
