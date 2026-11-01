
#include <stdio.h>
#include <string.h>

// Structure to store UART data
struct UART {
    char data[100];
    int baud_rate;
};

// Function to transmit data
void transmit(struct UART u) {
    printf("\nTransmitted Data: %s", u.data);
    printf("\nBaud Rate: %d", u.baud_rate);
}

// Function to receive data
void receive() {
    char received[100];

    printf("\nEnter received data: ");
    scanf(" %[^\n]", received);

    printf("Received Data: %s\n", received);
}

int main() {
    struct UART u;

    printf("Enter data to transmit: ");
    scanf(" %[^\n]", u.data);

    printf("Enter baud rate: ");
    scanf("%d", &u.baud_rate);

    // Transmit data
    transmit(u);

    // Receive data
    receive();

    return 0;
}
