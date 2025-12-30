/*

Resize an existing dynamic array using `realloc`.
```c
int* resize_array(int *arr, size_t old_size, size_t new_size);
```
Test: Create array of 5, fill it, resize to 10, fill rest, print all.

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void print_array(int *array, size_t length);
int* resize_array(int *array, size_t old_size, size_t new_size);

int main(void) {
    int *array = malloc(5 * sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Error allocating array.\n");

        return 1;
    }

    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
    }

    int *resized = resize_array(array, 5, 10);

    if (resized == NULL) {
        fprintf(stderr, "Error resizing array.\n");

        free(array); // If realloc fails, need to free the original pointer.
        // array = NULL; No need to nullify the pointer, as the function is about to return.

        return 1;
    }

    print_array(resized, 10);

    free(resized);
    resized = NULL;

    return 0;
}

// Caller must free!
int* resize_array(int *array, size_t old_size, size_t new_size) {
    if (old_size > new_size) {
        fprintf(stderr, "ERROR: Cannot shrink array!\n");

        return NULL;
    }

    int *resized = realloc(array, new_size * sizeof(int));

    if (resized == NULL)
        return NULL;

    for (size_t i = old_size; i < new_size; i++) {
        resized[i] = 0;
    }

    return resized;
}

static void print_array(int *array, size_t length) {
    printf("[ ");

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("]\n");
}
