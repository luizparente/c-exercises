/*

Write `my_strcpy()` that copies a string without using `strcpy()`.
```c
void my_strcpy(char *dest, const char *src);
```
Test: Copy `"World"` to a buffer, print both.

*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void my_strcpy(char dest[], const char src[]);

int main(void) {
    const char *src = "World";
    char dest[6] = {0};

    my_strcpy(dest, src);

    printf("Copied %zu characters.\n", strlen(dest));
    printf("%s\n", dest);

    return 0;
}

void my_strcpy(char dest[], const char src[]) {
    size_t index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }

    dest[index] = '\0';
}
