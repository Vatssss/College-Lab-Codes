#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, char *binary)
{
    if (num > 0)
    {
        decimalToBinary(num / 2, binary);
        sprintf(binary, "%s%d", binary, num % 2);
    }
}

int main(int argc, char *argv[])
{
    int n;
    FILE *ip, *op;
    sscanf(argv[1], "%d", &n);
    ip = fopen(argv[2], "r");
    op = fopen(argv[3], "w");

    int decNum;
    char binary[32];

    while (n-- > 0 && fscanf(ip, "%d", &decNum) == 1)
    {
        if (decNum == 0)
        {
            fprintf(op, "0\n");
        }
        else
        {
            binary[0] = '\0';
            decimalToBinary(decNum, binary);
            fprintf(op, "%s\n", binary);
        }
    }

    fclose(ip);
    fclose(op);
    printf("\nVatsal Saxena, 21051698, CSE-27");
    return 0;
}
