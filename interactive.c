/**
 * interactive_mode - interactive mode check
 * @information: struct
 * Return: 1 (interactive mode), 0 (otherwise)
 */

int interactive_mode(info_struct *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * custom_atoi - str to int conv
 * @str: string
 *
 * Return: 0 (success), conv num otherwise
 */

int custom_atoi(char *str)
{
	int i, s = 1, f = 0, out; /*flag = f, sign = s*/
	size_t result = 0;

	for (i = 0; str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
			s *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			f = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (s == -1)
		out = -result;
	else
		out = result;
	return (out);
}

/**
 * custom_isalpha - alphabetic char chec
 * @c: char
 *
 * Return: 1 (success), 0 (failure)
 */

int custom_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

