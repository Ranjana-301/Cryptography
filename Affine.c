#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_mod_inverse(int a) {
    int a_vals[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    int inv_vals[] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};
    for (int i = 0; i < 12; i++) {
        if (a == a_vals[i]) return inv_vals[i];
    }
    return -1;
}

int main() {
    char text[500], result[500], ch;
    int a, b, choice, s, t;

    printf("Affine Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter value of 'a' : ");
    scanf("%d", &a);
    printf("Enter value of 'b' : ");
    scanf("%d", &b);
    getchar(); 

    s = get_mod_inverse(a);
    if (s == -1 || b < 0 || b > 25) {
        printf("Invalid keys. 'a' must be coprime and 'b' in [0,25].\n");
        return 1;
    }

    printf("Enter the message: ");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (!isalpha(ch)) {
            printf("Invalid Message\n");
            return 1;
        }

        if (choice == 1) {
            if (islower(ch)) {
                ch = (a * (ch - 'a') + b) % 26 + 'A';
            } else {
                ch = (a * (ch - 'A') + b) % 26 + 'A';
            }
        } else if (choice == 2) {
            t = (s * (26 - b)) % 26;
            if (isupper(ch)) {
                ch = (s * (ch - 'A') + t) % 26 + 'a';
            } else {
                ch = (s * (ch - 'a') + t) % 26 + 'a';
            }
        } else {
            printf("Invalid choice.\n");
            return 1;
        }

        result[i] = ch;
    }

    result[strlen(text)] = '\0';

    if (choice == 1) {
        printf("Encrypted message: %s\n", result);
    } else {
        printf("Decrypted message: %s\n", result);
    }

    return 0;
}
