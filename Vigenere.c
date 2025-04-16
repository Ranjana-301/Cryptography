#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void to_lower_case(char *src) {
    while (*src != '\0') {
        if (isupper(*src)) *src = tolower(*src);
        src++;
    }
}

int main() {
    char text[500], key[100], ch;
    int choice, i, klen, tlen;

    printf("Vigenere Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%s", key);

    to_lower_case(text);
    to_lower_case(key);

    klen = strlen(key);
    tlen = strlen(text);

    for (i = 0; i < tlen; ++i) {
        ch = text[i];

        if (islower(ch)) {
            if (choice == 1) {
                ch = (ch - 'a' + key[i % klen] - 'a') % 26 + 'a';
            } else if (choice == 2) {
                ch = (ch - key[i % klen] + 26) % 26 + 'a';
            } else {
                printf("Invalid choice.\n");
                return 1;
            }
        } else {
            printf("Invalid Message\n");
            return 1;
        }

        text[i] = ch;
    }

    if (choice == 1) {
        printf("Encrypted message: %s\n", text);
    } else {
        printf("Decrypted message: %s\n", text);
    }

    return 0;
}
