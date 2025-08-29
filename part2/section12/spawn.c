/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:25:28 by hyamamot          #+#    #+#             */
/*   Updated: 2025/08/29 15:39:30 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		status;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <command> <arg>\n", argv[0]);
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		fprintf(stderr, "fork(2) failed\n");
		exit(1);
	}
	if (pid == 0)
	{
		execl(argv[1], argv[1], argv[2], NULL);
		perror(argv[1]);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		printf("child (PID=%d) finished;\n", pid);
		if (WIFEXITED(status))
			printf("exit, status%d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("signal, sig=%d\n", WTERMSIG(status));
		else
			printf("abnormal exit\n");
		exit(0);
	}
}
