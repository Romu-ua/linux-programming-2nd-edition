/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:46:19 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/28 19:51:09 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	FILE	*f;
	int		c;

	i = 1;
	while (i < argc)
	{
		f = fopen(argv[i], "r");
		if (!f)
		{
			perror(argv[i]);
			exit(1);
		}
		while ((c = fgetc(f)) != EOF)
		{
			if (putchar(c) < 0) exit(0);
		}
		i++;
	}
	exit(0);
}
