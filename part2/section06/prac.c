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
		while((c = fgetc(f)) != EOF)
		{
			if (c == '\t')
			{
				putchar('\\');
				putchar('t');
				continue ;
			}
			if (c == '\n')
			{
				putchar('$');
				putchar('\n');
				continue ;
			}
			if (putchar(c) < 0) 
				exit(0);
		}
		i++;
	}
	exit(0);
}
