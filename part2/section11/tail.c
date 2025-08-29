/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:07:59 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/29 15:17:06 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINE 2048

static void parse_args(int argc, char **argv, int *n, char **filename);
static FILE *open_file(const char *filename);
static char **alloc_buffer(int n);
static void free_buffer(char **buffer, int n);
static void read_last_lines(FILE *fp, char **buffer, int n, int *count, int *index);
static void print_tail(char **buffer, int n, int count, int index);
static void do_tail(const char *filename, int n);

int main(int argc, char **argv)
{
	int   n;
	char *filename;

	parse_args(argc, argv, &n, &filename);
	do_tail(filename, n);
	return (0);
}

static void parse_args(int argc, char **argv, int *n, char **filename)
{
	int i;

	*n = DEFAULT_LINES;
	*filename = NULL;
	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], "-n") == 0)
		{
			if (i + 1 >= argc)
			{
				fprintf(stderr, "Usage: %s [-n num] [file]\n", argv[0]);
				exit(1);
			}
			*n = atoi(argv[i + 1]);
			i += 2;
			continue;
		}
		*filename = argv[i];
		i++;
	}
	if (*n <= 0)
		*n = DEFAULT_LINES;
}

static FILE *open_file(const char *filename)
{
	FILE *fp;

	if (filename)
	{
		fp = fopen(filename, "r");
		if (!fp)
		{
			perror("fopen");
			exit(1);
		}
		return fp;
	}
	return stdin;
}

static char **alloc_buffer(int n)
{
	char **buffer;
	int    i;

	buffer = (char **)malloc(sizeof(char *) * n);
	if (!buffer)
	{
		perror("malloc");
		exit(1);
	}
	i = 0;
	while (i < n)
	{
		buffer[i] = NULL;
		i++;
	}
	return buffer;
}

static void free_buffer(char **buffer, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

static void read_last_lines(FILE *fp, char **buffer, int n, int *count, int *index)
{
	char line[MAX_LINE];

	*count = 0;
	*index = 0;
	while (fgets(line, sizeof(line), fp))
	{
		free(buffer[*index]);
		buffer[*index] = strdup(line);
		if (!buffer[*index])
		{
			perror("strdup");
			exit(1);
		}
		*index = (*index + 1) % n;
		(*count)++;
	}
}

static void print_tail(char **buffer, int n, int count, int index)
{
	int start;
	int total;
	int i;
	int pos;

	if (count <= 0)
		return;
	start = (count >= n) ? index : 0;
	total = (count >= n) ? n : count;
	i = 0;
	while (i < total)
	{
		pos = (start + i) % n;
		if (buffer[pos])
			fputs(buffer[pos], stdout);
		i++;
	}
}

static void do_tail(const char *filename, int n)
{
	FILE *fp;
	char **buffer;
	int    count;
	int    index;

	fp = open_file(filename);
	buffer = alloc_buffer(n);
	read_last_lines(fp, buffer, n, &count, &index);
	print_tail(buffer, n, count, index);
	free_buffer(buffer, n);
	if (fp != stdin)
		fclose(fp);
}

