#include "main.h"
#include <unistd.h>  /* For write function */
#include <stddef.h>  /* For NULL */

/* Implementations of the specified functions */

int _putchar(char c) {
    return write(1, &c, 1);
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c) {
    return ((_islower(c)) || (c >= 'A' && c <= 'Z'));
}

int _abs(int n) {
    return (n < 0 ? -n : n);
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int len = 0;
    while (*s++) len++;
    return len;
}

void _puts(char *s) {
    while (*s) _putchar(*s++);
    _putchar('\n');
}

char *_strcpy(char *dest, char *src) {
    char *temp = dest;
    while ((*dest++ = *src++));
    return temp;
}

int _atoi(char *s) {
    int res = 0, sign = 1;
    while (*s == ' ') s++;
    if (*s == '-' || *s == '+') {
        if (*s == '-') sign = -1;
        s++;
    }
    while (_isdigit(*s)) {
        res = res * 10 + (*s - '0');
        s++;
    }
    return res * sign;
}

char *_strcat(char *dest, char *src) {
    char *temp = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return temp;
}

char *_strncat(char *dest, char *src, int n) {
    char *temp = dest;
    while (*dest) dest++;
    while (n-- && (*dest++ = *src++));
    if (n < 0) *dest = '\0';
    return temp;
}

char *_strncpy(char *dest, char *src, int n) {
    char *temp = dest;
    while (n-- && (*dest++ = *src++));
    while (n-- > 0) *dest++ = '\0';
    return temp;
}

int _strcmp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *_memset(char *s, char b, unsigned int n) {
    char *temp = s;
    while (n--) *s++ = b;
    return temp;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *d = dest;
    const char *s = src;
    while (n--) *d++ = *s++;
    return dest;
}

char *_strchr(char *s, char c) {
    while (*s) {
        if (*s == c) return s;
        s++;
    }
    return (*s == c) ? s : NULL;
}

unsigned int _strspn(char *s, char *accept) {
    char *p;
    unsigned int count = 0;
    while (*s) {
        for (p = accept; *p; p++) {
            if (*s == *p) {
                count++;
                break;
            }
        }
        if (*p == '\0') return count;
        s++;
    }
    return count;
}

char *_strpbrk(char *s, char *accept) {
    char *p;
    while (*s) {
        for (p = accept; *p; p++) {
            if (*s == *p) return s;
        }
        s++;
    }
    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    char *h, *n;
    if (!*needle) return haystack;
    while (*haystack) {
        h = haystack;
        n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) return haystack;
        haystack++;
    }
    return NULL;
}
