/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prac1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:28:13 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/29 16:32:06 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char	name[32];
	int		age;
};

static struct person *make_person(void)
{
	struct person *p = malloc(sizeof(struct person));
	if (!p)
		exit(1);
	strcpy(p->name, "Taro");
	p->age = 20;

	return (p);
}

int	main(void)
{
	struct person *p;

	p = make_person();
	printf("Name: %s, Age: %d\n", p->name, p->age);
	free(p);
	return (0);
}
