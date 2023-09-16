#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

ssize_t custom_getline(int fd, char **lineptr, size_t *n)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t bytesRead = 0;
    static ssize_t bufferPos = 0;
    char *line;
    size_t pos;
    char c;
    char *new_line

    if (*lineptr == NULL || *n == 0)
    {
        *n = BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
       	{
            return (-1);
        }
    }
    
    *line = *lineptr;
    pos = 0;

    while (1)
    {
        if (bufferPos == bytesRead)
       	{
            bytesRead = read(fd, buffer, BUFFER_SIZE);
            if (bytesRead <= 0)
	    {
                if (pos == 0) 
		{
                    return (-1);
                } 
		else
		{
                    break;
                }
            }
            bufferPos = 0;
        }

        c = buffer[bufferPos++];

        if (pos >= *n - 1)
	{
            *n *= 2;
            *new_line = (char *)realloc(line, *n);
            if (new_line == NULL)
	    {
                free(line);
                return (-1);
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
    return ((ssize_t)pos);
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int fileDescriptor = open("example.txt", O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Failed to open the file");
        return (1);
    }

    printf("Contents of the file:\n");

    while ((read = custom_getline(fileDescriptor, &line, &len)) != -1) {
        printf("%s", line);
    }

    close(fileDescriptor);
    free(line);
    return (0);
}

