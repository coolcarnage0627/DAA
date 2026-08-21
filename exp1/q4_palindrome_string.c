#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char str[200], cleaned[200];
    int i, j = 0, len, isPalindrome = 1;

    printf("Enter a string: ");
    getchar();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char)str[i])) {
            cleaned[j++] = tolower((unsigned char)str[i]);
        }
    }
    cleaned[j] = '\0';

    len = j;
    for (i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
