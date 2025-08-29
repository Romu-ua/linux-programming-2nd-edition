/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:46:32 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/29 16:54:33 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_student
{
	char	name[32];
	int		score;
}	s_student;

static s_student *create_students(int n)
{
	s_student	*arr;
	int			i;

	arr = (s_student *)malloc(sizeof(s_student) * n);
	i = 0;
	while (i < n)
	{
		sprintf(arr[i].name, "Student %d", i);
		arr[i].score = (i + 1) * 10;
		i++;
	}
	return (arr);
}

int	main(void)
{
	static int	n = 3;
	s_student	*list;
	int			i;

	list = create_students(n);
	i = 0;
	while (i < n)
	{
		printf("name: %s\nscore: %d\n", list[i].name, list[i].score);
		i++;
	}
	free(list);
	return (0);
}
