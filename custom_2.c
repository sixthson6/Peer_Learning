#include "main.h"

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    char *line = *lineptr;
    size_t pos = 0;
    char c;
    char *new_line;

    if (*lineptr == NULL || *n == 0) {
        *n = CHUNK_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
        line = *lineptr;
    }

    while (1) {
        c = fgetc(stream);

        if (c == EOF) {
            if (pos == 0) {
                return -1;
            } else {
                break;
            }
        }

        if (pos >= *n - 1) {
            *n *= 2;
          new_line = (char *)realloc(line, *n);
            if (new_line == NULL) {
                free(line);
                *lineptr = NULL;
                return -1;
            }
            line = new_line;
            *lineptr = line;
        }

        line[pos++] = c;

        if (c == '\n') {
            break;
        }
    }

    line[pos] = '\0';
    return pos;
}
