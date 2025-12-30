/*

Count occurrences of a specific character in a string.
```c
size_t count_char(const char *str, char c);
```
Test: Count 'l' in `"Hello World"` → `3`

*/

#include <stdio.h>

size_t count_char(const char *string, char c);

int main(void) {
    char test[] = "Hello, World!";
    char lookup = 'l';
    size_t count = count_char(test, lookup);

    printf("String '%s' contains %zu characters '%c'.\n", test, count, lookup);

    return 0;
}

size_t count_char(const char *string, char c) {
    size_t count = 0;

    while (*string) {
        if (*string == c) {
            count++;
        }

        string++;
    }

    return count;
}
