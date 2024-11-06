#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    int len;
    printf("Enter a string (max 255 characters): ");
    fgets(str, 256, stdin);
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    printf("Inverted string: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
    printf("String of even elements: ");
    for (int i = 1; i < len; i += 2) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
