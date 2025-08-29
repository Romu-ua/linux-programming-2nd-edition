/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:42:41 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/28 22:59:21 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	do_head(FILE *f, long nlines);

int	main(int argc, char **argv)
{
	int		nlines;
	int		i;
	FILE	*f;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s n [file file ...]]\n", argv[0]);
		exit(1);
	}
	nlines = atol(argv[1]);
	if (argc == 2)
		do_head(stdin, nlines);
	else
	{
		i = 2;
		while (i < argc)
		{
			f = fopen(argv[i], "r");
			if (!f)
			{
				perror(argv[i]);
				exit(1);
			}
			do_head(f, nlines);
			fclose(f);
			i++;
		}
	}
	exit(0);
}

static void	do_head(FILE *f, long nlines)
{
	int	c;

	if (nlines <= 0) return ;
	while ((c = getc(f)) != EOF)
	{
		if (putchar(c) < 0) exit(1);
		if (c == '\n')
			nlines--;
			if (nlines == 0)
				return ;
	}
}
