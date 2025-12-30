/*

Split a string by spaces into an array of strings (dynamically allocated).
```c
char** str_split(const char *str, size_t *count);
```
Test: `"Hello World"` → `["Hello", "World"]`, set `count` to 2, caller frees each string + array.

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(const char *str, size_t *count);

int main(void)
{
    size_t count;
    char **result;

    /* Test 1 */
    result = str_split("Hello World", &count);
    printf("Test 1: %zu words\n", count);
    if (result != NULL) {
        for (size_t i = 0; i < count; i++) {
            printf("  Word %zu: '%s'\n", i, result[i]);
            free(result[i]);  /* Free each string */
        }
        free(result);  /* Free array */
    }

    /* Test 2 */
    result = str_split("One Two Three Four", &count);
    printf("Test 2: %zu words\n", count);
    if (result != NULL) {
        for (size_t i = 0; i < count; i++) {
            printf("  Word %zu: '%s'\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    /* Test 3 */
    result = str_split("  Extra   Spaces  ", &count);
    printf("Test 3: %zu words\n", count);
    if (result != NULL) {
        for (size_t i = 0; i < count; i++) {
            printf("  Word %zu: '%s'\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    /* Test 4 */
    result = str_split("Single", &count);
    printf("Test 4: %zu words\n", count);
    if (result != NULL) {
        for (size_t i = 0; i < count; i++) {
            printf("  Word %zu: '%s'\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    /* Test 5 */
    result = str_split("", &count);
    printf("Test 5: %zu words\n", count);
    if (result != NULL) {
        for (size_t i = 0; i < count; i++) {
            printf("  Word %zu: '%s'\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    }

    return 0;
}

char** str_split(const char *str, size_t *count)
{
    if (str == NULL || count == NULL) {
        if (count != NULL) *count = 0;
        return NULL;
    }

    *count = 0;

    /* First pass: count words */
    size_t word_count = 0;
    int in_word = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    /* Handle empty string or no words */
    if (word_count == 0) {
        return NULL;
    }

    /* Allocate array of pointers */
    char **result = malloc(word_count * sizeof(char*));
    if (result == NULL) {
        return NULL;
    }

    /* Second pass: extract words */
    size_t word_index = 0;
    size_t word_start = 0;
    in_word = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (in_word) {
                /* End of word */
                size_t word_len = i - word_start;
                result[word_index] = malloc(word_len + 1);
                if (result[word_index] == NULL) {
                    /* Cleanup on failure */
                    for (size_t j = 0; j < word_index; j++) {
                        free(result[j]);
                    }
                    free(result);
                    return NULL;
                }
                strncpy(result[word_index], &str[word_start], word_len);
                result[word_index][word_len] = '\0';
                word_index++;
                in_word = 0;
            }
        } else if (!in_word) {
            /* Start of new word */
            in_word = 1;
            word_start = i;
        }
    }

    /* Handle last word if string doesn't end with space */
    if (in_word) {
        size_t word_len = strlen(str) - word_start;
        result[word_index] = malloc(word_len + 1);
        if (result[word_index] == NULL) {
            for (size_t j = 0; j < word_index; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        strncpy(result[word_index], &str[word_start], word_len);
        result[word_index][word_len] = '\0';
        word_index++;
    }

    *count = word_count;
    return result;
}
