#include "monty.h"

/**
 * main - entry into the monty
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *buff, *token;
	int fds, is_p = 0;
	unsigned int line = 1;
	ssize_t f_read;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fds = open(argv[1], O_RDONLY);
	if (fds == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
		return (0);
	f_read = read(fds, buff, 10000);
	if (f_read == -1)
	{
		free(buff);
		close(fds);
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (is_p == 1)
		{
			push(&h, line, token);
			is_p = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_p = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_fun(token) != 0)
			{
				get_op_fun(token)(&h, line);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h);
	free(buff);
	close(fds);
	return (0);
}
