/*

Replace all occurrences of a character with another.
```c
char* replace_char(const char *str, char old, char new);
```
Test: Replace 'o' with 'a' in `"Hello World"` → `"Hella Warld"`

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace_char(const char *str, char old, char new);

int main(void) {
    char test[] = "Hello World";
    char *result = replace_char(test, 'o', 'a');

    if (!result) {
        fprintf(stderr, "ERROR: Unable to allocate heap memory for array.");

        return 1;
    }

    printf("%s\n", result);

    free(result);
    result = NULL;

    return 0;
}

// Caller must free.
char* replace_char(const char *str, char old, char new) {
    size_t size = strlen(str);
    char *result = malloc(size + 1); // +1 for '\0'. sizeof(char) always 1.

    if (!result) {
        return NULL;
    }

    char *iterator = result;

    while (*str) {
        if (*str == old) {
            *iterator = new;
        }
        else {
            *iterator = *str;
        }

        iterator++;
        str++;
    }

    result[size] = '\0';

    return result;
}
