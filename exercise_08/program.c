/*

Create a new string that's the concatenation of two strings (allocate dynamically).
```c
char* str_concat(const char *s1, const char *s2);
```
Test: `"Hello" + " World"` → return new string `"Hello World"`, caller frees.

*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char* str_concat(const char *s1, const char *s2);

#include <stdio.h>

int main(void) {
    char *test = str_concat("Hello, ", "World!");

    if (!test) {
        fprintf(stderr, "Error allocating memory for str_concat.\n");

        return 1;
    }

    printf("%s\n", test);

    free(test);
    test = NULL;

    return 0;
}

// Manual implementation.
// Caller must free.
char* str_concat(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    char *result = malloc(s1_len + s2_len + 1); // char is 1 byte long. +1 for \0.

    if (!result) {
        return NULL;
    }

    for (size_t i = 0; i < s1_len; i++) {
        result[i] = s1[i];
    }

    for (size_t i = 0; i < s2_len; i++) {
        result[s1_len + i] = s2[i];
    }

    result[s1_len + s2_len] = '\0';

    return result;
}

// Optimized implementation using C libs.
// Caller must free!
char* str_concat2(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1);

    if (!result) {
        return NULL;
    }

    memcpy(result, s1, len1);           /* Copy s1 */
    memcpy(result + len1, s2, len2);    /* Copy s2 after s1 */

    result[len1 + len2] = '\0';         /* Null terminate */

    return result;
}
