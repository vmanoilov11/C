#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return 1;
    }
    return 0;
}

void extractVowels(const char *str) {
    printf("Vowel: ");
    for (int i = 0; i < strlen(str); i++) {
        if (isVowel(str[i])) {
            printf("%c ", str[i]);
        }
    }
    printf("\n");
}

int main() {
    char str[1000];

    printf("String: ");
    fgets(str, sizeof(str), stdin);
    extractVowels(str);

    return 0;
}
