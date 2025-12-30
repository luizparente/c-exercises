/*

Check if a string is a palindrome (reads same forwards and backwards).
```c
int is_palindrome(const char *str);
```
Test: `"racecar"` → `1` (true), `"hello"` → `0` (false)

*/

#include <stdio.h>
#include <string.h>

int is_palindrome(const char *string);

int main(void) {
    printf("%s\n", is_palindrome("racecar") ? "Palindrome!" : "Not palindrome.");
    printf("%s\n", is_palindrome("hello") ? "Palindrome!" : "Not palindrome.");
    printf("%s\n", is_palindrome("a") ? "Palindrome!" : "Not palindrome.");
    printf("%s\n", is_palindrome("") ? "Palindrome!" : "Not palindrome.");

    return 0;
}

int is_palindrome(const char *string) {
    size_t size = strlen(string);
    const char *front = string;
    const char *back = string + size - 1;
    int is_palindrome = 1;

    while (front < back) { // Iterate until pointers meet.
        if (*front != *back) {
            is_palindrome = 0;

            break;
        }

        front++;
        back--;
    }

    return is_palindrome;
}
