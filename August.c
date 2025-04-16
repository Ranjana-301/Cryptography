#include<stdio.h>
#include<ctype.h>

int main() {
    char text[500], ch;
    int choice;

    printf("August Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalnum(ch)) {
            if (choice == 1) {
                if (islower(ch)) {
                    ch = (ch - 'a' + 1) % 26 + 'a';
                }
                if (isupper(ch)) {
                    ch = (ch - 'A' + 1) % 26 + 'A';
                }
                if (isdigit(ch)) {
                    ch = (ch - '0' + 1) % 10 + '0';
                }
            } else if (choice == 2) {
                if (islower(ch)) {
                    ch = (ch - 'a' - 1 + 26) % 26 + 'a';
                }
                if (isupper(ch)) {
                    ch = (ch - 'A' - 1 + 26) % 26 + 'A';
                }
                if (isdigit(ch)) {
                    ch = (ch - '0' - 1 + 10) % 10 + '0';
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
