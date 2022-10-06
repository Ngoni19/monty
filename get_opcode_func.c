#include "monty.h"

/**
 * get_op_fun - get correct operation function
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op_fun(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{"pop", pop},
		{"nop", nop},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int k = 0;

	while (instruction_s[k].f != NULL)
	{
		if (strcmp(token1, instruction_s[k].opcode) == 0)
			return (instruction_s[k].f);
		k++;
	}
	return (NULL);
}
