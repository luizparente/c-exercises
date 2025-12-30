/*

Count the number of words in a string (words separated by spaces).
```c
size_t word_count(const char *str);
```
Test: `"Hello World from C"` → `4`

*/

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t word_count(const char *string);

int main(void) {
    const char *string = "Hello World from C";

    printf("%zu words found.\n", word_count(string));

    return 0;
}

size_t word_count(const char *string) {
    size_t words = 0;
    int in_word = 0; // 0 means false, 1 means true.

    while (*string) {
        if (isspace(*string)) {
            in_word = 0;
        }
        else {
            if (!in_word) {
                words++;
            }

            in_word = 1;
        }

        string++;
    }

    return words;
}
