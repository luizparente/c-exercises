# C Programming Exercises

## Beginner Level (1-5): Basic String and Array Operations

### Exercise 1: String Length
Write `my_strlen()` that calculates string length without using `strlen()`.
```c
size_t my_strlen(const char *str);
```
Test: `my_strlen("Hello")` → `5`

### Exercise 2: String Copy
Write `my_strcpy()` that copies a string without using `strcpy()`.
```c
void my_strcpy(char *dest, const char *src);
```
Test: Copy `"World"` to a buffer, print both.

### Exercise 3: String Concatenation
Write `my_strcat()` that appends one string to another.
```c
void my_strcat(char *dest, const char *src);
```
Test: `"Hello" + " World"` → `"Hello World"`

### Exercise 4: Character Count
Count occurrences of a specific character in a string.
```c
size_t count_char(const char *str, char c);
```
Test: Count 'l' in `"Hello World"` → `3`

### Exercise 5: String Reverse (In-Place)
Reverse a string in place using pointers.
```c
void reverse_string(char *str);
```
Test: `"Hello"` → `"olleH"`

---

## Intermediate Level (6-10): Pointers and Dynamic Memory

### Exercise 6: Dynamic Array Allocation
Create an array of `n` integers on the heap, initialize to values 0 through n-1.
```c
int* create_array(size_t n);
```
Test: Create array of 10, print all values, free it.

### Exercise 7: String Duplication (my_strdup)
Duplicate a string using dynamic memory allocation.
```c
char* my_strdup(const char *str);
```
Test: Duplicate `"Hello, World!"`, modify copy, free it.

### Exercise 8: Concatenate with Allocation
Create a new string that's the concatenation of two strings (allocate dynamically).
```c
char* str_concat(const char *s1, const char *s2);
```
Test: `"Hello" + " World"` → return new string `"Hello World"`, caller frees.

### Exercise 9: String to Integer
Convert a string to an integer (like `atoi`).
```c
int my_atoi(const char *str);
```
Test: `"12345"` → `12345`, `"-42"` → `-42`

### Exercise 10: Array Resize
Resize an existing dynamic array using `realloc`.
```c
int* resize_array(int *arr, size_t old_size, size_t new_size);
```
Test: Create array of 5, fill it, resize to 10, fill rest, print all.

---

## Advanced Level (11-15): Complex String Operations

### Exercise 11: Word Count
Count the number of words in a string (words separated by spaces).
```c
size_t word_count(const char *str);
```
Test: `"Hello World from C"` → `4`

### Exercise 12: String Split
Split a string by spaces into an array of strings (dynamically allocated).
```c
char** str_split(const char *str, size_t *count);
```
Test: `"Hello World"` → `["Hello", "World"]`, set `count` to 2, caller frees each string + array.

### Exercise 13: Remove Character
Create a new string with all occurrences of a character removed.
```c
char* remove_char(const char *str, char c);
```
Test: Remove 'o' from `"Hello World"` → `"Hell Wrld"`

### Exercise 14: String Replace
Replace all occurrences of a character with another.
```c
char* replace_char(const char *str, char old, char new);
```
Test: Replace 'o' with 'a' in `"Hello World"` → `"Hella Warld"`

### Exercise 15: Palindrome Check
Check if a string is a palindrome (reads same forwards and backwards).
```c
int is_palindrome(const char *str);
```
Test: `"racecar"` → `1` (true), `"hello"` → `0` (false)

---
