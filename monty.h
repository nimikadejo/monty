#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

extern int global_var[];

/* Block of codes to check for general monty program errors */
void check_usage(int argc);
void check_file(char *filename);
void check_file_access(FILE *fp, char *filename);
void check_opcode(void (*opcode)(), int line_no, char *cmd);
void check_fail(char *line, FILE *fp, stack_t *head);

/** stack functions */
int add_to_queue(stack_t **head, int n);
int add_to_stack(stack_t **head, int n);
int print_stack(stack_t **head);
void free_stack(stack_t *head);
int delete_stack_head(stack_t **head);
int delete_stack_end(stack_t **head);

/* Block of operationcodes and how to check them */
void push_(stack_t **stack, unsigned int lineno);
void pall_(stack_t **stack, unsigned int lineno);
void pop_(stack_t **stack, unsigned int lineno);
void add_(stack_t **stack, unsigned int lineno);
void pint_(stack_t **stack, unsigned int lineno);

void (*get_opcode_func(char *s))(stack_t **stack, unsigned int lineno);

/* opcode_func2.c */
void swap_(stack_t **stack, unsigned int lineno);
void nop_(stack_t **stack, unsigned int lineno);
void pchar_(stack_t **stack, unsigned int lineno);
void pstr_(stack_t **stack, unsigned int lineno);

/* opcode_func3.c */
void rotl_(stack_t **stack, unsigned int lineno);
void rotr_(stack_t **stack, unsigned int lineno);
void stack_(stack_t **stack, unsigned int lineno);
void queue_(stack_t **stack, unsigned int lineno);

/* opcode_func4.c */
void sub_(stack_t **stack, unsigned int lineno);
void div_(stack_t **stack, unsigned int lineno);
void mul_(stack_t **stack, unsigned int lineno);
void mod_(stack_t **stack, unsigned int lineno);

/* helper.c */
int check_if_number(char *str);
int check_if_push(char **tok_line, int lineno);
int is_ascii(int c);
void check_data_structure(char *opcode);

/* string_helper.c */
int tokenize_line(char *s, char *tokens[]);
void clear_strings(char *tokens[]);
int check_empty(const char *s);
int check_if_comment(char **token);

char *strtok_r(char *s, const char *delim, char **saveptr);

#endif
