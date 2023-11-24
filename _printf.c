#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;

    int *allocated_memory = (int *)malloc(10 * sizeof(int));

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                char buffer[20];
                int length = snprintf(buffer, sizeof(buffer), "%d", num);
                write(1, buffer, length);
                printed_chars += length;
            } else if (*format == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int length = snprintf(buffer, sizeof(buffer), "%u", num);
                write(1, buffer, length);
                printed_chars += length;
            } else if (*format == 'o') {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int length = snprintf(buffer, sizeof(buffer), "%o", num);
                write(1, buffer, length);
                printed_chars += length;
            } else if (*format == 'x' || *format == 'X') {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int length = snprintf(buffer, sizeof(buffer), "%x", num);
                write(1, buffer, length);
                printed_chars += length;
            } else if (*format == 'p') {
                void *ptr = va_arg(args, void*);
                char buffer[20];
                int length = snprintf(buffer, sizeof(buffer), "%p", ptr);
                write(1, buffer, length);
                printed_chars += length;
            } else if (*format == 'c') {
                char character = (char) va_arg(args, int);
                write(1, &character, 1);
                printed_chars++;
            } else if (*format == 's') {
                char *str = va_arg(args, char*);
                int length = 0;
                while (str[length] != '\0') {
                    length++;
                }
                write(1, str, length);
                printed_chars += length;
            } else if (*format == '%') {
                write(1, "%r", 1);
                printed_chars++;
            } else if (*format == 'r') {
                write(1, "\%r", 7);
                printed_chars += 7;
            } else if (*format == 'n') {
                int *n = va_arg(args, int*);
                *n = printed_chars;
            }
        } else {
            write(1, format, 1);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    free(allocated_memory);

    return printed_chars;
}
