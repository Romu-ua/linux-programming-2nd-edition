/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:32:58 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/29 16:46:03 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_book {
	char	title[64];
	int		pages;
} s_book;

static s_book *create_book(const char *title, int pages)
{
	s_book *b;

	b = (s_book *)malloc(sizeof(s_book));
	if (!b)
		exit(1);
	strncpy(b->title, title, sizeof(b->title) - 1);
	b->title[sizeof(b->title) - 1] = '\0';
	b->pages = pages;
	return (b);
}

int	main(int argc, char **argv)
{
	s_book	*b;

	if (argc != 3)
	{
		fprintf(stderr, "Uage: %s <book title: string> <page: int>", argv[0]);
		exit(1);
	}
	b = create_book(argv[1], atoi(argv[2]));
	printf("title: %s\npages: %d\n", b->title, b->pages);
	free(b);
	return (0);
}
