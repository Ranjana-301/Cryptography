#include <stdio.h>
#include <string.h>
#include <ctype.h>

char getCipherChar(char p, char k);
char getPlainChar(char c, char k);

int main() {
    char text[1024], key[1024], finalKey[1024];
    int choice;

    printf("Autoclave Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message : ");
    scanf("%s", text);

    printf("Enter the key : ");
    scanf("%s", key);

    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        if (!isalpha(text[i])) {
            printf("Invalid Message (only alphabetic characters allowed)\n");
            return 1;
        }
    }

    for (int i = 0; i < keyLen; i++) {
        if (!isalpha(key[i])) {
            printf("Invalid Key (only alphabetic characters allowed)\n");
            return 1;
        }
    }

    if (choice == 1) {
        for (int i = 0; i < keyLen; i++) {
            finalKey[i] = tolower(key[i]);
        }
        for (int i = keyLen, j = 0; i < textLen; i++, j++) {
            finalKey[i] = tolower(text[j]);
        }
        finalKey[textLen] = '\0';

        for (int i = 0; i < textLen; i++) {
            text[i] = getCipherChar(tolower(text[i]), finalKey[i]);
        }
        printf("Encrypted message: %s\n", text);
    } else if (choice == 2) {
        for (int i = 0; i < keyLen; i++) {
            finalKey[i] = tolower(key[i]);
        }

        for (int i = 0; i < textLen; i++) {
            char decrypted = getPlainChar(tolower(text[i]), finalKey[i]);
            text[i] = decrypted;
            finalKey[keyLen + i] = decrypted;
        }

        printf("Decrypted message: %s\n", text);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}

char getCipherChar(char p, char k) {
    return ((p - 'a' + (k - 'a')) % 26) + 'a';
}

char getPlainChar(char c, char k) {
    return ((c - 'a' - (k - 'a') + 26) % 26) + 'a';
}
