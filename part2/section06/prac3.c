#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

int	main(int argc, char **argv)
{
	int				i;
	FILE			*in;
	unsigned char	buf[BUFFER_SIZE];
	size_t			n;
	
	i = 1;
	while (i < argc)
	{
		in = fopen(argv[i], "r");
		if (!in)
		{
			perror(argv[i]);
			exit(1);
		}
		while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
		{
			if (fwrite(buf, 1, n, stdout) != n)
			{
				perror("fwrite");
				exit(1);
			}
		}
		i++;
	}
	return (0);
}
