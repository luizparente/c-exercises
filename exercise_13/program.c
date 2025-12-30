/*

Create a new string with all occurrences of a character removed.
```c
char* remove_char(const char *str, char c);
```
Test: Remove 'o' from `"Hello World"` → `"Hell Wrld"`

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_char(const char *string, char c);

int main(void) {
    char *test = "Hello, World!";
    char *new = remove_char(test, 'l');

    if (new == NULL) {
        fprintf(stderr, "Memory error.\n");

        return 1;
    }

    printf("%s\n", new);

    free(new);
    new = NULL;

    return 0;
}

// Caller must free!
char* remove_char(const char *string, char c) {
    int chars_to_remove = 0;
    size_t original_length = 0;

    while (*string) {
        if (*string == c) {
            chars_to_remove++;
        }

        string++;
        original_length++;
    }

    string -= original_length; // Pointer rewind.

    size_t new_size = original_length - chars_to_remove;
    char *new = malloc(new_size + 1); // sizeof(char) is always one. +1 for '\0'.

    if (new == NULL) {
        return NULL;
    }

    while (*string) {
        if (*string != c) {
            *new = *string;

            new++;
        }

        string++;
    }

    new -= new_size; // Pointer rewind.
    new[new_size] = '\0';

    return new;
}
