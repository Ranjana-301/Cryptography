#include<stdio.h>
#include<ctype.h>

int main() {
    char text[500], ch;
    int choice;

    printf("Atbash Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = 'z' - (ch - 'a');
            } else if (isupper(ch)) {
                ch = 'Z' - (ch - 'A');
            }
            text[i] = ch;
        } else {
            printf("Invalid Message\n");
            return 1;
        }
    }

    if (choice == 1) {
        printf("Encrypted message: %s\n", text);
    } else {
        printf("Decrypted message: %s\n", text);
    }

    return 0;
}
