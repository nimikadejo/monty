#include "monty.h"

/**
 * swap_ - swaps the value of the first two elements on the stack
 * @stack: head to the stack
 * @lineno: line number where opcode is located
 */

void swap_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;
	int temp_value;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp_value = temp->n;
	temp->n = temp2->n;
	temp2->n = temp_value;
}

/**
 * nop_ - operation does nothing
 * @stack: head to the stack
 * @lineno: line number where opcode is located
 */
void nop_(stack_t **stack, unsigned int lineno)
{
	(void) stack;
	(void) lineno;
}

/**
 * pchar_ - prints teh char at the top of the stack
 * @stack: head to the stack
 * @lineno: line number where opcode is located
 */
void pchar_(stack_t **stack, unsigned int lineno)
{
	int c;
	stack_t *temp;

	temp = (*stack);
	if (temp == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", lineno);
		global_var[2] = 1;
		return;
	}
	c = temp->n;
	if (!(is_ascii(c)))
	{
		printf("L%d: can't pchar, value out of range\n", lineno);
		global_var[2] = 1;
		return;
	}
	putchar(c);
	putchar('\n');
}

/**
 * pstr_ - prints the string starting at the stack
 * @stack: head to the top of the stack
 * @lineno: line number of the opcode
 * Description: string stops where stack is over, the value is 0 or the value
 * is not an ascii value
 */
void pstr_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp;
	int c;

	(void) lineno;
	temp = (*stack);
	while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
	{
		c = temp->n;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}
