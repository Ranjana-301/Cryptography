#include<stdio.h>
#include<ctype.h>

int main() {
    char text[500], ch;
    int key, choice;

    printf("Caesar Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalnum(ch)) {
            if (choice == 1) {
                if (islower(ch)) {
                    ch = (ch - 'a' + key) % 26 + 'a';
                }
                if (isupper(ch)) {
                    ch = (ch - 'A' + key) % 26 + 'A';
                }
                if (isdigit(ch)) {
                    ch = (ch - '0' + key) % 10 + '0';
                }
            } else if (choice == 2) {
                if (islower(ch)) {
                    ch = (ch - 'a' - key + 26) % 26 + 'a';
                }
                if (isupper(ch)) {
                    ch = (ch - 'A' - key + 26) % 26 + 'A';
                }
                if (isdigit(ch)) {
                    ch = (ch - '0' - key + 10) % 10 + '0';
                }
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
