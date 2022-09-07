#include "monty.h"

/**
 * rotl_ - rotates the top element of the stack to the bottom
 * @stack: head of the stack
 * @lineno: line number
 */
void rotl_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	(void) lineno;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		(*stack) = (*stack)->next;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		temp->prev = temp2;
		temp->next->prev = NULL;
		temp->next = NULL;
	}
}

/**
 * rotr_ - rotates the last element of the stack to the top
 * @stack: head of the stack
 * @lineno: line number
 */
void rotr_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	(void) lineno;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		(*stack) = temp2;
	}
}

/**
 * stack_ - sets the format of the data to a stack
 * @stack: head of the stack
 * @lineno: line number
 */
void stack_(stack_t **stack, unsigned int lineno)
{
	(void) stack;
	(void) lineno;
}

/**
 * queue_ - sets the format of the data to a queue
 * @stack: head of the stack
 * @lineno: line number of the opcode
 */
void queue_(stack_t **stack, unsigned int lineno)
{
	(void) stack;
	(void) lineno;
}
