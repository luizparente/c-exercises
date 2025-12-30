/*

Write `my_strlen()` that calculates string length without using `strlen()`.
```c
size_t my_strlen(const char *str);
```
Test: `my_strlen("Hello")` → `5`

*/

#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char string[]);

int main(void) {
    char *test = "Hello";
    size_t length = my_strlen(test);

    printf("Length: %zu\n.", length);

    return 0;
}

size_t my_strlen(const char string[]) {
    int count = 0;
    const char *current = string;

    while (*current != '\0') {
        count++;
        current++;
    }

    return count;
}
