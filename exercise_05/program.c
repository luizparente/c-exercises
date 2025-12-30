/*

Reverse a string in place using pointers.
```c
void reverse_string(char *str);
```
Test: `"Hello"` → `"olleH"`

*/

#include <stdio.h>

void reverse_string(char *string);

int main(void) {
    // char test* = "Hello"; // <- This points to READ-ONLY memory! Would not work here.
    char test[] = "Hello"; // <- Mutable array. Works here, as we modify the array in-place.
    reverse_string(test);

    printf("%s\n", test);

    return 0;
}

void reverse_string(char *string) {
    size_t length = 0;

    while (*string) {
        length++;
        string++;
    }

    string -= length; // Gotta rewind the pointer!

    for (size_t i = 0; i < length / 2; i++) {
        char temp = string[i];

        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}
