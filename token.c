#include "monty.h"

/**
 * get_opcode_func - selects the correct function to perform the opcode
 * @s: opcode passed to the program
 * Return: a pointer to the function given the opcode or NULL.
 */
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int lineno)
{
	int i;
	instruction_t stk[] = {
		{"pall", pall_},
		{"push", push_},
		{"pop", pop_},
		{"add", add_},
		{"swap", swap_},
		{"pint", pint_},
		{"nop", nop_},
		{"pchar", pchar_},
		{"pstr", pstr_},
		{"rotl", rotl_},
		{"rotr", rotr_},
		{"sub", sub_},
		{"div", div_},
		{"mul", mul_},
		{"mod", mod_},
		{"queue", queue_},
		{"stack", stack_},
		{NULL, NULL}
	};


	i = 0;
	while (i < 17)
	{
		if (strcmp(s, (stk[i]).opcode) == 0)
		{
			return (*(stk[i]).f);
		}
		i++;
	}
	return (NULL);
}
