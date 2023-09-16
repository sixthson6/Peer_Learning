#include "main.h"

#define CHUNK_SIZE 128

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[CHUNK_SIZE];
    static size_t bufferPos = 0;
    static size_t bytesRead = 0;
    ssize_t charsRead = 0;
    char *line = *lineptr;
    size_t pos = 0;
    char *new_line;
    char c;

    if (*lineptr == NULL || *n == 0) {
        *n = CHUNK_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }

    while (1) {
        if (bufferPos == bytesRead) {
            bytesRead = fread(buffer, 1, CHUNK_SIZE, stream);
            if (bytesRead == 0) {
                if (pos == 0) {
                    return -1;
                } else {
                    break;
                }
            }
            bufferPos = 0;
        }

        c = buffer[bufferPos++];
        charsRead++;

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
    return charsRead;
}
