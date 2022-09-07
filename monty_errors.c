#include "monty.h"

/**
 * check_usage - checks whether correct arguments are given
 * @argc: argument count
 */
void check_usage(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file - Checks if file given can be opened
 * @filename: path to file
 */
void check_file(char *filename)
{
	char *file_ext;

	file_ext = strrchr(filename, '.');
	if (file_ext == NULL)
		return;
	if (!(strcmp(".txt", file_ext) == 0 || strcmp(".m", file_ext) == 0))
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file_access - Checks if the file can be opened/accessed
 * @fp: file pointer with a FILE return
 * @filename: name of file
 */
void check_file_access(FILE *fp, char *filename)
{
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_opcode - Checks if opcode function pointer is NULL
 * @opcode: the opcode function pointer
 * @line_no: error line number
 * @cmd: pointer to the command given
 */
void check_opcode(void (*opcode)(), int line_no, char *cmd)
{
	if (opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", line_no, cmd);
		global_var[2] = 1;
		return;
	}
}

/**
 * check_fail - checks if any form of error has been occured, 
 * in order to stop running code
 * @line: line to free due to improper execution
 * @fp: file ptr with a return
 * @head: ptr to head of the stack
 * Return: return 1 on exit, Otherwise 0.
 */
void check_fail(char *line, FILE *fp, stack_t *head)
{
	if (global_var[2] == 1)
	{
		free(line);
		fclose(fp);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
