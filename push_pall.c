#include "monty.h"

/**
 * push_ - pushes a value to the stack
 * @stack: the head of the stack
 * @lineno: line number where the opcode is located
 */
void push_(stack_t **stack, unsigned int lineno)
{
	int result;

	if (global_var[1] == 0)
		result = add_to_stack(stack, global_var[0]);
	else
		result = add_to_queue(stack, global_var[0]);
	if (result < 0)
	{
		printf("L%d: usage: push integer\n", ln);
		global_var[2] = 1;
		return;
	}
}

/**
 * pall_ - prints all values of the stack
 * @stack: the head of the stack
 * @lineno: line number where the opcode is located
 */
void pall_(stack_t **stack, unsigned int lineno)
{
	int result;
	(void) lineno;

	result = print_stack(stack);
	if (result != 0)
	{
		;
	}
}
