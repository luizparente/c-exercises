/*

Duplicate a string using dynamic memory allocation.
```c
char* my_strdup(const char *str);
```
Test: Duplicate `"Hello, World!"`, modify copy, free it.

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* my_strdup(const char *string);

int main(void) {
    char test[] = "Hello, World!";
    char *dupe = my_strdup(test);

    if (!dupe) {
        fprintf(stderr, "ERROR: Unable to allocate memory for array.");

        return 1;
    }

    printf("%s\n", dupe);

    free(dupe);
    dupe = NULL;

    return 0;
}

// Caller must free!
char* my_strdup(const char *string) {
    size_t size = 0;

    while (*string) {
        size++;
        string++;
    }

    string -= size; // <- Rewind!

    char *duplicate = malloc(size + 1); // size does not account for \0.

    if (!duplicate) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        duplicate[i] = string[i];
    }

    duplicate[size] = '\0';

    return duplicate;
}
