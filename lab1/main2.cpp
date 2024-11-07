#include <stdio.h>
#include <string.h>

int main1() {
    char str[256];
    int len, i;

    printf("Enter a string (max 255 characters): ");
    fgets(str, 256, stdin);

    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Inverted string: ");
    i = len - 1;
inverted_loop:
    if (i < 0) goto end_inverted;
    putchar(str[i]);
    i--;
    goto inverted_loop;
end_inverted:
    printf("\n");

    printf("String of even elements: ");
    i = 1;
even_loop:
    if (i >= len) goto end_even;
    putchar(str[i]);
    i += 2;
    goto even_loop;
end_even:
    printf("\n");

    return 0;
}
