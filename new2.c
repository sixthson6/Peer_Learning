#include "main.h"

/**
 * custom_my_history - Displays the command history list with line numbers.
 * @commandInfo: Struct
 * Return: Always 0.
 */
int custom_my_history(info_struct *commandInfo)
{
    print_text_list(commandInfo->command_history);
    return (0);
}

/**
 * custom_unset_alias - Unsets an alias
 * @commandInfo: struct.
 * @str: string.
 * Return: 0 (success) 1 on error.
 */
int custom_unset_alias(info_struct *commandInfo, char *text)
{
    char *equals_sign, temp_char;
    int ret;

    equals_sign = custom_strchr(text, '=');
    if (!equals_sign)
        return (1);
    temp_char = *equals_sign;
    *equals_sign = 0;
    ret = delete_n_by_index(&(commandInfo->command_aliases),
                               get_node_with_index(commandInfo->command_aliases, node_with(commandInfo->command_aliases, text, -1)));
    *equals_sign = temp_char;
    return (ret);
}

/**
 * custom_set_alias - Sets an alias for a command.
 * @commandInfo: Parameter struct.
 * @str: The string alias.
 * Return: 0 on success, 1 on error.
 */
int custom_set_alias(info_struct *commandInfo, char *text)
{
    char *equals_sign;

    equals_sign = custom_strchr(text, '=');
    if (!equals_sign)
        return (1);
    if (!*++equals_sign)
        return (custom_unset_alias(commandInfo, text));

    custom_unset_alias(commandInfo, text);
    return (append_list_node(&(commandInfo->command_aliases), text, 0) == NULL);
}

/**
 * custom_print_alias - Prints an alias for a command.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error.
 */

int custom_print_alias(list_struct *node)
{
    char *equals_sign = NULL, *alias = NULL;

    if (node)
    {
        equals_sign = custom_strchr(node->text, '=');
        for (alias = node->text; alias <= equals_sign; alias++)
            _print(*alias);
        _print('\'');
        _print(equals_sign + 1);
        _print("'\n");
        return (0);
    }
    return (1);
}

/**
 * custom_myalias - (man alias).
 * @commandInfo: Struct.
 *
 * Return: 0.
 */
int custom_myalias(info_struct *commandInfo)
{
    int i = 0;
    char *equals_sign = NULL;
    list_struct *node = NULL;

    if (commandInfo->argument_count == 1)
    {
        node = commandInfo->command_aliases;
        while (node)
        {
            custom_print_alias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; commandInfo->arguments_list[i]; i++)
    {
        equals_sign = custom_strchr(commandInfo->arguments_list[i], '=');
        if (equals_sign)
            custom_set_alias(commandInfo, commandInfo->arguments_list[i]);
        else
            custom_print_alias(node_starts_with(commandInfo->command_aliases, commandInfo->arguments_list[i], '='));
    }

    return (0);
}
