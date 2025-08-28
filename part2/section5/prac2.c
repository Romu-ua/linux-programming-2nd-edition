/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:04:08 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/28 19:26:19 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

static void die(const char *s);

int main(int argc, char **argv)
{
	int				i;
	int				n;
	unsigned char	buf[BUFFER_SIZE];
	int				cnt;
	int				fd;
	
	if (argc != 2)
	{
		fprintf(stderr, "%s: only one file can be recevied.", argv[0]);
		exit(1);
	}
	cnt = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) die(argv[1]);
	n = read(fd, buf, sizeof buf);
	if (n < 0) die(argv[1]);
	i = 0;
	while (i < n)
	{
		if (buf[i] == '\n') cnt++;
		i++;
	}
	printf(" \\n cnt: %d\n", cnt);

	
	return (0);
}

static void	die(const char *s)
{
	perror(s);
	exit(1);
}
