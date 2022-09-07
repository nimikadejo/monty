#include "monty.h"

/**
 * sub_ - subtracts the top element of stack from the second element
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void sub_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * div_ - divides the second top element of stack from the top element
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void div_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", lineno);
		global_var[2] = 1;
		return;
	}

	temp->n = (int)(temp2->n / temp->n);
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * mul_ - multiplies the top two elements of the stack
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void mul_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n * temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * mod_ - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void mod_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp->n = temp2->n % temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}
