/*

Write `my_strcat()` that appends one string to another.
```c
void my_strcat(char *dest, const char *src);
```
Test: `"Hello" + " World"` → `"Hello World"`

*/

#include <stdio.h>

void my_strcat(char dest[], const char src[]);

int main(void) {
    char test[20] = "Hello, ";

    my_strcat(test, "World!");

    printf("%s\n", test);

    return 0;
}

/** We assume dest has enough memory slots allocated to it. */
void my_strcat(char dest[], const char src[]) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';
}
