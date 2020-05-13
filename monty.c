#include "monty.h"
/**
 * main - The main of our program
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 in succes 1 if fails
**/
int main(int argc, char *argv[])
{
	FILE *file_name;
	char single_line[150];
	char **tokenized;
	int i = 1, it = 0, n = 0, f = 0;
	stack_t *head = NULL;
	instruction_t func_dict[] = {{"push", funct_push}, {"pall", funct_pall},
				     {"pint", funct_pint}, {NULL, NULL}};
	if (argc < 2)
		printf("USAGE: monty file\n"), exit (EXIT_FAILURE);
	file_name =  fopen(argv[1], "r");
	if (file_name == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	for(;fgets(single_line, 150, file_name) != NULL; i++)
	{
		tokenized = tokenizer(single_line);
		for (it = 0; func_dict[it].opcode; it++)
			if (strcmp(tokenized[0], func_dict[it].opcode) == 0)
			{
				if (tokenized[1])
					n = atoi(tokenized[1]);
				func_dict[it].f(&head, n);
			}
		for(f = 0; tokenized[f] != NULL; f++)
			free(tokenized[f]);
		free(tokenized);
	}
	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
	head = NULL;
	fclose(file_name); return (0);
	return (0);
}
