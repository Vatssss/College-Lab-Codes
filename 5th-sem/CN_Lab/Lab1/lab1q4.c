#include <stdio.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    struct pkt packet;
    int number;

    // Input the values for the structure members
    printf("Enter a number (less than 1000): ");
    scanf("%d", &number);
    if (number >= 1000)
    {
        printf("Number should be less than 1000. Exiting...\n");
        return 1;
    }

    packet.ch1 = number / 100 + '0';   // Convert the hundreds digit to char
    number %= 100;                     // Remove the hundreds digit from the original number
    packet.ch2[0] = number / 10 + '0'; // Convert the tens digit to char
    packet.ch2[1] = number % 10 + '0'; // Convert the ones digit to char
    packet.ch3 = '\0';                 // Null-terminate the char array

    // Display the content of each member of the structure
    printf("\nContent of the structure:\n");
    printf("ch1: %c\n", packet.ch1);
    printf("ch2: %c%c\n", packet.ch2[0], packet.ch2[1]);
    printf("ch3: %c\n", packet.ch3);

    // Aggregate the members of the structure to form the original number
    int reconstructed_number = (packet.ch1 - '0') * 100 + (packet.ch2[0] - '0') * 10 + (packet.ch2[1] - '0');

    // Display the reconstructed number
    printf("\nReconstructed number: %d\n", reconstructed_number);

    return 0;
}
