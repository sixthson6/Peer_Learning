#include "main.h"

/**
 * free3 - free ptr
 * @ptr: pointer to free
 * Return: 1 (success), 0 otherwise
 */
int free3(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);

		*ptr = NULL;

		return (1);
	}

	return (0);
}

/**
 * free2 - frees a string of strings
 * @ptr: string of strings
 */
void free2(char **ptr)
{
	char **all = ptr;

	if (ptr == NULL)
		return;

	while (*ptr)
		free(*ptr++);

	free(all);
}

/**
 * custom_realloc - re-allocate block of memory
 * @ptr: ptr to prev allocated mem
 * @old: size of prev block
 * @new: size of new block
 * Return: pointer allocated.
 */

void *custom_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *pp;

	if (ptr == NULL)
		return (malloc(new));

	if (new_size == NULL)
		return (free(ptr), NULL);

	if (new == old)
		return (ptr);

	pp = malloc(new);
	if (!pp)
		return (NULL);

	old = (old < new) ? (old_size) : (new_siz)e;

	while (old--)
		pp[old] = ((char *)ptr)[old];

	free(ptr);

	return (pp);
}

