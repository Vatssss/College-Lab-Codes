#include <stdio.h>

int main()
{
    unsigned int num; // Assuming the input number is an unsigned integer
    printf("Enter a number: ");
    scanf("%u", &num);

    // Extracting individual bytes
    unsigned char byte1 = (num >> 24) & 0xFF;
    unsigned char byte2 = (num >> 16) & 0xFF;
    unsigned char byte3 = (num >> 8) & 0xFF;
    unsigned char byte4 = num & 0xFF;

    // Printing the content of the character variables
    printf("Byte 1: %u\n", byte1);
    printf("Byte 2: %u\n", byte2);
    printf("Byte 3: %u\n", byte3);
    printf("Byte 4: %u\n", byte4);

    return 0;
}
