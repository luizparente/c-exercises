/*

Create an array of `n` integers on the heap, initialize to values 0 through n-1.
```c
int* create_array(size_t n);
```
Test: Create array of 10, print all values, free it.

*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int* create_array(size_t n);

int main(void) {
    size_t size = 10;
    int *test = create_array(size);

    if (!test) {
        fprintf(stderr, "ERROR: Unable to allocate memory for array.\n");

        return 1;
    }

    for (size_t i = 0; i < size; i++) {
        printf("%d ", test[i]);
    }

    printf("\n");

    free(test);
    test = NULL;

    return 0;
}

/*
 * Creates an array of ints of size n.
 *
 * NOTE: Caller must free the memory.
 */
int* create_array(size_t n) {
    int *array = malloc(n * sizeof(int));

    if (!array) {
        return NULL;
    }

    for (size_t i = 0; i < n; i++) {
        array[i] = i;

        // printf("%p\n", (void*)&array[i]); // <- Uncomment this to see the memory addresses of each allocated array slot.
    }

    return array;
}
