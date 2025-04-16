#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100], ch;
    int choice;

    printf("Myszkowski Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%s", key);

    for (int i = 0; text[i]; i++) text[i] = tolower(text[i]);
    for (int i = 0; key[i]; i++) key[i] = tolower(key[i]);

    int msg_len = strlen(text);
    int key_len = strlen(key);
    int rows = (msg_len + key_len - 1) / key_len;
    char matrix[rows][key_len];
    char result[100] = "";
    int order[100] = {0};
    char sorted[100];
    int used[100] = {0};

    strcpy(sorted, key);
    for (int i = 0; i < key_len - 1; i++) {
        for (int j = i + 1; j < key_len; j++) {
            if (sorted[i] > sorted[j]) {
                char tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }

    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < key_len; j++) {
            if (!used[j] && key[i] == sorted[j]) {
                order[i] = j;
                used[j] = 1;
                break;
            }
        }
    }

    if (choice == 1) {
        memset(matrix, 'x', sizeof(matrix));
        int idx = 0;
        for (int i = 0; i < rows && idx < msg_len; i++) {
            for (int j = 0; j < key_len && idx < msg_len; j++) {
                matrix[i][j] = text[idx++];
            }
        }

        for (int step = 0; step < key_len; step++) {
            for (int col = 0; col < key_len; col++) {
                if (order[col] == step) {
                    for (int row = 0; row < rows; row++) {
                        result[strlen(result)] = matrix[row][col];
                    }
                }
            }
        }

        result[msg_len] = '\0';
        printf("Encrypted message: %s\n", result);
    }

    else if (choice == 2) {
        memset(matrix, 'x', sizeof(matrix));
        int pos = 0;
        for (int step = 0; step < key_len; step++) {
            for (int col = 0; col < key_len; col++) {
                if (order[col] == step) {
                    for (int row = 0; row < rows; row++) {
                        if (pos < msg_len)
                            matrix[row][col] = text[pos++];
                    }
                }
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < key_len; col++) {
                result[strlen(result)] = matrix[row][col];
            }
        }

        result[msg_len] = '\0';
        printf("Decrypted message: %s\n", result);
    }

    else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
