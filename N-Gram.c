#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void remove_spaces(char *str) {
    int i, j = 0;
    char temp[100];
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i]))
            temp[j++] = str[i];
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void encrypt_ngram(char *message, int n) {
    char cipher[100] = "";
    int len = strlen(message);
    for (int i = 0; i < len; i += n) {
        for (int j = (i + n - 1); j >= i && j < len; j--) {
            strncat(cipher, &message[j], 1);
        }
    }
    printf("Encrypted message: %s\n", cipher);
}

void decrypt_ngram(char *cipher, int n) {
    char message[100] = "";
    int len = strlen(cipher);
    for (int i = 0; i < len; i += n) {
        for (int j = (i + n - 1); j >= i && j < len; j--) {
            strncat(message, &cipher[j], 1);
        }
    }
    printf("Decrypted message: %s\n", message);
}

int main() {
    char input[100];
    int choice, n;

    printf("N-Gram Cipher\n");
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter the message: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter N (size of n-gram): ");
    scanf("%d", &n);

    to_lowercase(input);
    remove_spaces(input);

    if (choice == 1) {
        encrypt_ngram(input, n);
    } else if (choice == 2) {
        decrypt_ngram(input, n);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
