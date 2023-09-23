#include "main.h"

/**
 * custom_strncmp - compares two strings and returns their difference
 * @s1: first string
 * @s2: second string
 * @bytes: no. of bytes to compare
 *
 * Return: number of bytes that differ
 */

int custom_strncmp(char *s1, char *s2, unsigned int bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	if (i == bytes)
		return (0);
	return ((unsigned char)s2[i] - (unsigned char)s1[i]);
}

/**
 * custom_atoi - converts a string to an integer
 * @str: string
 *
 * Return: converted integer
 */
int custom_atoi(char *str)
{
	int sign, result, i = 0;

	/* convert string */
	for (i = result = 0, sign = 1; str[i]; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
			result = 10 * result - (str[i] - '0');

		if (result < 0 && (str[i] < '0' || str[i] > '9'))
			break;
	}

	if (sign > 0)
		result *= -1;

	return (result);
}

/**
  * custom_strdup - duplicates str
  * @str: str to copy
  *
  * Return: pointer to allocated space
  */

char *custom_strdup(char *str)
{
	int length, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	length = custom_strlen(str);
	if (length < 0)
		return (NULL);
	length++;
	dest = malloc((length) * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		dest[i] = str[i];

	dest[i - 1] = '\0';

	return (dest);
}

/**
  * custom_strcat - concat 2 str and reallocates
  * @dest: destination
  * @src: source
  *
  * Return: ptr to concat str
  */

char *custom_strcat(char *dest, char *src)
{
	size_t dest_length, src_length, i;

	dest_length = custom_strlen(dest);
	src_length = custom_strlen(src);
	dest = realloc_function(dest, dest_length, dest_length + src_length + 1);

	if (dest == NULL)
		return (NULL);

	for (i = 0; i < src_length; i++)
	{
		dest[i + dest_length] = src[i];
	}

	dest[i + dest_length] = '\0';

	return (dest);
}
