#include "monty.h"

/**
 * add_to_queue - adds the nodes to the end of the queue
 * @head: head of the queue
 * @n: number value for the queue
 * Return: 1 on success, otherwise -1
 */
int add_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		temp_node = *head;
		while (temp_node->next != NULL)
			temp_node = temp_node->next;
		temp_node->next = new_node;
		new_node->prev = temp_node;
	}
	return (1);
}
