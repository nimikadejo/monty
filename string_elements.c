#include "monty.h"

/**
 * clear_strings - Reset strings in an array
 * @tokens: array of strings
 */
void clear_strings(char *tokens[])
{
	int i;

	for (i = 0; tokens[i]; i++)
		tokens[i][0] = '\0';
}

/**
 * check_empty - Checks if a string is empty
 * @s: string to check
 * Return: 1 if empty, 0 otherwise
 */
int check_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * check_if_comment - Checks if line is comment and changes it accordingly
 * @token: pointer to token string
 * Return: 1 if comment, 0 if not a comment
 */
int check_if_comment(char **token)
{
	if (*token[0] == '#')
	{
		*token[0] = '\0';
		return (1);
	}
	return (0);
}
