#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[200],result[400];
    int key[2][2] = {{3, 3}, {2, 5}};
    int i, j,letters[200],count = 0,resultIndex = 0;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters[count++] = toupper(text[i]) - 'A';
        }
    }

    if (count % 2 != 0) {
        letters[count++] = 'X' - 'A';
    }

    int encrypted[200];

    for (i = 0; i < count; i += 2) {
        encrypted[i] =
            (key[0][0] * letters[i] +
             key[0][1] * letters[i + 1]) % 26;

        encrypted[i + 1] =
            (key[1][0] * letters[i] +
             key[1][1] * letters[i + 1]) % 26;
    }

    int letterIndex = 0;

    for (i = 0; text[i] != '\0' && text[i] != '\n'; i++) {

        if (isalpha(text[i])) {
            result[resultIndex++] = encrypted[letterIndex++] + 'A';
        } else {
            result[resultIndex++] = text[i];
        }
    }

    if (letterIndex < count) {
        result[resultIndex++] = encrypted[letterIndex] + 'A';
    }

    result[resultIndex] = '\0';

    printf("Ciphertext: %s\n", result);

    return 0;
}