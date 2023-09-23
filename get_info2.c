#include "main.h"

/**
 * fetch_node_index - get node index
 * @head: head ptr
 * @current_node: current node
 * Return: node index or -1
 */
ssize_t fetch_node_index(list_struct *head, list_struct *current_node)
{
	unsigned int n = 0;

	while (head)
	{
		if (head == current_node)
			return (n);
		head = head->next;
		n++;
	}

	return (-1);
}

/**
 * lislen - find len of linked list
 * @head: first node ptr
 * Return: linked list size
 */
size_t lislen(const list_t *head)
{
	size_t n = 0;

	while (head)
	{
		head = head->next;
		n++;
	}

	return (n);
}

/**
 * list_prefix - returns starting prefix
 * @head: ptr to head
 * @pref: matched str
 * @c: the next character 
 * after prefix to match
 * Return: match node or null
 */
list_struct *list_prefix(list_stuct *head, char *pref, char c)
{
	char *prev = NULL;

	while (head)
	{
		prev = starts_with(head->str, pref);
		if (prev && ((c == -1) || (*prev == c)))
			return (head);
		head = head->next;
	}

	return (NULL);
}

/**
 * strings_list - find arr of strings
 * @head: ptr to 1st node
 * Return: arr of strings
 */

char **string_list(list_struct *head)
{
	list_struct *current_node = head;
	unsigned int i = lislen(head), j;
	char **strs1;
	char *str2;

	if (!head || !i)
		return (NULL);
	/*dynamic allocation*/
	strs1 = malloc(sizeof(char *) * (i + 1));
	if (!strs1)
		return (NULL);
	for (i = 0; current_node; current_node = current_node->next, i++)
	{
		str2 = malloc(custom_strlen(current_node->str) + 1);
		/*allocate space*/
		if (!str2)
		{
			for (j = 0; j < i; j++)
				free(strs1[j]);
			free(strs1);
			return (NULL);
		}

		str2 = custom_strcpy(str2, current_node->str);
		strs1[i] = str;
	}

	strs1[i] = NULL;

	return (strs1);
}


