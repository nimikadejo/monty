#include "monty.h"

/**
 * pop_ - removes the top element of the stack
 * @stack: the head of the stack
 * @lineno: line number where the opcode is located
 */
void pop_(stack_t **stack, unsigned int lineno)
{
	int result;

	result = delete_stack_head(stack);
	if (result != 1)
	{
		printf("L%d: can't pop an empty stack\n", lineno);
		global_var[2] = 1;
		return;
	}
}

/**
 * add_ - adds the top two elements of the stack
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void add_(stack_t **stack, unsigned int lineno)
{
	stack_t *temp;
	stack_t *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", lineno);
		global_var[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp->next->n + temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * pint_ - print value at top of stack followed by new line
 * @stack: head to the stack
 * @lineno: line number where the opcode is located
 */
void pint_(stack_t **stack, unsigned int lineno)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", lineno);
		global_var[2] = 1;
		return;
	}

	printf("%d\n", head->n);
}
