
### 1. `strlen()`
Calculates the length of a string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, world!";
    size_t length = strlen(str);
    printf("Length of the string is: %zu\n", length);
    return 0;
}
```

### 2. `strcpy()` and `strncpy()`
Copies one string to another.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    // Using strcpy
    strcpy(dest, src);
    printf("Copied string using strcpy: %s\n", dest);

    // Using strncpy (copying only 5 characters)
    strncpy(dest, src, 5);
    dest[5] = '\0'; // Null-terminate the string
    printf("Copied string using strncpy: %s\n", dest);

    return 0;
}
```

### 3. `strcat()` and `strncat()`
Appends one string to another.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[30] = "Hello";
    char src[] = ", world!";

    // Using strcat
    strcat(dest, src);
    printf("Concatenated string using strcat: %s\n", dest);

    // Resetting dest
    strcpy(dest, "Hello");

    // Using strncat (appending only 5 characters)
    strncat(dest, src, 5);
    printf("Concatenated string using strncat: %s\n", dest);

    return 0;
}
```

### 4. `strcmp()` and `strncmp()`
Compares two strings lexicographically.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello, world!";

    // Using strcmp
    int result = strcmp(str1, str2);
    printf("Comparison result using strcmp: %d\n", result);

    // Using strncmp (comparing only first 5 characters)
    result = strncmp(str1, str2, 5);
    printf("Comparison result using strncmp: %d\n", result);

    return 0;
}
```

### 5. `strchr()` and `strrchr()`
Finds the first or last occurrence of a character in a string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    char ch = 'o';

    // Using strchr
    char *firstOccurrence = strchr(str, ch);
    if (firstOccurrence) {
        printf("First occurrence of '%c': %s\n", ch, firstOccurrence);
    }

    // Using strrchr
    char *lastOccurrence = strrchr(str, ch);
    if (lastOccurrence) {
        printf("Last occurrence of '%c': %s\n", ch, lastOccurrence);
    }

    return 0;
}
```

### 6. `memcpy()` and `memmove()`
Copies memory blocks.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    // Using memcpy
    memcpy(dest, src, strlen(src) + 1);
    printf("Copied string using memcpy: %s\n", dest);

    // Using memmove (for overlapping memory)
    char overlap[] = "Hello, world!";
    memmove(overlap + 6, overlap, strlen("Hello") + 1);
    printf("Result after memmove: %s\n", overlap);

    return 0;
}
```

### 7. `strtok()`
Tokenizes a string using a delimiter.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This is C programming.";
    char *token;

    // Using strtok to split the string by spaces
    token = strtok(str, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
```

