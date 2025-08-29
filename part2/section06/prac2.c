#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	FILE	*f;
	int		c;
	int		cnt;

	i = 1;
	cnt = 0;
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
			if (c == '\n')
				cnt++;
		}
		i++;
	}
	printf("\\n cnt is  %d\n", cnt);
}
