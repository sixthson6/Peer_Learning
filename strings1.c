#include "main.h"

/**
 * custom_strcat - concatenates two strings
 * @dest: destination str
 * @src: source str
 *
 * Return: ptrto destination str
 */
char *custom_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (tmp);
}

/**
 * custom_strlen - finds length of a string
 * @str: the string
 *
 * Return: length of string
 */

int custom_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * custom_strcmp - performs comparison of two strangs.
 * @str1: first strang
 * @str2: second strang
 *
 * Return: negative if s1 < s2,
 * positive if s1 > s2, zero if s1 == s2
 */
int custom_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * needle_check - find needle in haystack
 * @search_string: string to search
 * @sub_str: the search substring
 *
 * Return: address of next char of search_string NULL
 */
char *needle_check(const char *search_string, const char *sub_str)
{
	while (*sub_str)
	{
		if (*sub_str++ != *search_string++)
			return (NULL);
	}

	return ((char *)search_string);
}
