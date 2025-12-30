# Important Standard Library Funcions

## String Functions (string.h)

strlen(str)              // String length (not including '\0')
strcpy(dest, src)        // Copy string (dangerous - no bounds check)
strcat(dest, src)        // Concatenate (dangerous - no bounds check)
strcmp(s1, s2)           // Compare strings
strchr(str, ch)          // Find character
strstr(haystack, needle) // Find substring

## Memory Functions (stdlib.h)

malloc(size)            // Allocate uninitialized memory
calloc(n, size)         // Allocate zeroed memory
realloc(ptr, new_size)  // Resize allocation
free(ptr)               // Free allocated memory

## Character Functions (ctype.h)

isspace(c)   // Is whitespace?
isdigit(c)   // Is digit?
isalpha(c)   // Is letter?
toupper(c)   // Convert to uppercase
tolower(c)   // Convert to lowercase

## I/O Functions (stdio.h)

printf(fmt, ...)         // Print to stdout
fprintf(stream, fmt, ...)// Print to specific stream
sprintf(buffer, fmt, ...)// Print to string
