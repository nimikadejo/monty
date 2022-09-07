#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int global_var;

/* Block of codes to check for general monty program errors */
void check_usage(int argc);
void check_file(char *filename);
void check_file_access(FILE *fp, char *filename);
void check_opcode(void (*opcode)(), int line_no, char *cmd);
void check_fail(char *line, FILE *fp, stack_t *head);
int add_to_queue(stack_t **head, int n);

/* Block of operationcodes and how to check them */
void push_(stack_t **stack, unsigned int lineno);
void pall_(stack_t **stack, unsigned int lineno);
void (*get_opcode_func(char *s));

#endif
