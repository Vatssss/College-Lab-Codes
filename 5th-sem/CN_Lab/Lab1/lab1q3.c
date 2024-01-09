#include <stdio.h>

int main()
{
    unsigned int number;
    printf("Enter a number: ");
    scanf("%u", &number);
    unsigned char byte1 = (unsigned char)((number / 1000000) % 10);
    unsigned char byte2 = (unsigned char)((number / 10000) % 100);
    unsigned char byte3 = (unsigned char)((number / 100) % 100);
    unsigned char byte4 = (unsigned char)(number % 100);
    printf("Byte 1: %u\n", byte1);
    printf("Byte 2: %u\n", byte2);
    printf("Byte 3: %u\n", byte3);
    printf("Byte 4: %u\n", byte4);
    return 0;
}
