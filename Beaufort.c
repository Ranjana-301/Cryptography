#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char text[500], key[100], ch;
    int choice;

    printf("Beaufort Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%s", key); 

    int keyLength = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isalpha(ch)) {
            char keyChar = toupper(key[j % keyLength]) - 'A'; 

            if (choice == 1) {  
                if (isupper(ch)) {
                    ch = (keyChar - (ch - 'A') + 26) % 26 + 'A';
                }
                if (islower(ch)) {
                    ch = (keyChar - (ch - 'a') + 26) % 26 + 'a';
                }
            } else if (choice == 2) {  
                if (isupper(ch)) {
                    ch = (keyChar - (ch - 'A') + 26) % 26 + 'A';
                }
                if (islower(ch)) {
                    ch = (keyChar - (ch - 'a') + 26) % 26 + 'a';
                }
            } else {
                printf("Invalid choice.\n");
                return 1;
            }

            j++;  
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
