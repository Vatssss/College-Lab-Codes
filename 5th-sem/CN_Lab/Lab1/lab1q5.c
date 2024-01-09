#include <stdio.h>
union EndiannessChecker
{
    int num;
    char bytes[sizeof(int)];
};
int isLittleEndian()
{
    union EndiannessChecker check;
    check.num = 1;
    return check.bytes[0];
}
int swapEndianness(int num) // bitwise shifting
{
    return ((num >> 24) & 0xFF) |
           ((num >> 8) & 0xFF00) |
           ((num << 8) & 0xFF0000) |
           ((num << 24) & 0xFF000000);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isLittleEndian())
    {
        printf("Host machine is Little Endian.\n");
    }
    else
    {
        printf("Host machine is Big Endian.\n");
    }
    printf("Content of each byte location:\n");
    union EndiannessChecker check;
    check.num = num;
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("Byte %d: %02X\n", i + 1, check.bytes[i]);
    }
    int converted_num = swapEndianness(num);
    printf("Converted number: %d\n", converted_num);
    return 0;
}
