#include "monty.h"
/**
 * tokenizer - returns a matrix of a strtoked string
 * @line: string to tokenize
 * @head: head of the list to malloc and to free
 * Return: A double pointer containing the splied string by delimiters
 */
char **tokenizer(char *line)
{
	char **argv = NULL;
	char *argc = NULL;
	char *writer = NULL;
	char *linecpy = NULL;
	char *linecpy2 = NULL;
	int iter1 = 0, iter2 = 0;

	linecpy = strdup(line);
	linecpy2 = strdup(line);
	if (linecpy == NULL)
	{
		return (NULL);
	}
	argc = strtok(linecpy, DELIMITER);
	while (argc != NULL)
	{
		argc = strtok(NULL, DELIMITER);
		iter1++;
	}
	argv = malloc((iter1 + 1) * sizeof(char *));
	if (argv == NULL)
	{
		return (NULL);
	}
	writer = strtok(linecpy2, DELIMITER);
	while (writer != NULL && iter2 <= iter1)
	{
		argv[iter2] = strdup(writer);
		argv[iter2][strlen(writer)] = '\0';
		writer = strtok(NULL, DELIMITER);
		iter2++;
	}
	free(linecpy);
	free(linecpy2);
	argv[iter1] = NULL;
	return (argv);
}
