#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[7]; // 6 characters for the hexadecimal code and 1 for null terminator
    unsigned int r, g, b;

    // Input hexadecimal color code (without the '#' symbol)
    printf("Enter a hexadecimal color code (e.g., FF00FF): ");
    scanf("%6s", hex);

    // Convert the hexadecimal color code to RGB
    if (sscanf(hex, "%2x%2x%2x", &r, &g, &b) != 3) {
        printf("Invalid input. Please enter a valid hexadecimal color code.\n");
        return (1);
    }

    printf("RGB: (%d, %d, %d)\n", r, g, b);
}