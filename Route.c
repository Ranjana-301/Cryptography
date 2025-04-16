#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], result[100] = "";
    int choice, rows, cols, len;

    printf("Route Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message : ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", &rows);

    len = strlen(text);
    cols = (len + rows - 1) / rows;

    char matrix[rows][cols];
    int index = 0;

    if (choice == 1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (index < len)
                    matrix[i][j] = text[index++];
                else
                    matrix[i][j] = 'x';
            }
        }

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                result[strlen(result)] = matrix[i][j];
            }
        }

        result[rows * cols] = '\0';
        printf("Encrypted message: %s\n", result);
    }

    else if (choice == 2) {
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (index < len)
                    matrix[i][j] = text[index++];
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[strlen(result)] = matrix[i][j];
            }
        }

        result[len] = '\0';
        printf("Decrypted message: %s\n", result);
    }

    else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
