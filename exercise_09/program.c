/*

Convert a string to an integer (like `atoi`).
```c
int my_atoi(const char *str);
```
Test: `"12345"` → `12345`, `"-42"` → `-42`

*/

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

int my_atoi(const char *string);

int main(void) {
    printf("String '%s' converts to %d.\n", "12345", my_atoi("12345"));
    printf("String '%s' converts to %d.\n", "+42", my_atoi("+42"));
    printf("String '%s' converts to %d.\n", "-42", my_atoi("-42"));

    return 0;
}

int my_atoi(const char *string) {
    int sum = 0;
    int multiplier = 1;

    while (*string != '\0') {
        if (*string == '-') {
            multiplier = -1;
            string++;

            continue;
        }
        else if (*string == '+' || isspace(*string)) {
            string++;

            continue;
        }

        int parsed = *string++ - '0'; // Better than -48.

        sum = sum * 10 + parsed; // Same as multiplying by 10^(some exponent) each time. But this is more efficient.
    }

    return sum * multiplier;
}
