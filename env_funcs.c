#include "main.h"

/**
 * build_environ - build/populates environment linked list in main.h
 * @info: Struct containing arguments,
 * used to maintain constant function prototype.
 *
 * Return: 0 (Success)
 */

int build_environ(info_t *info)
{
	list_struct *node = NULL;
	unsigned int i;

	for (i = 0; environ[i]; i++)
		append_list_node(&node, environ[i], 0);

	information->env = node;

	return (0);
}

