#include <stdbool.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	bool	c[256];
	int		i;
	char	*str;

	if (argc == 3)
	{
		i = 0;
		while (i < 256)
			c[i++] = false;
		str = argv[2];
		i = 0;
		while (str[i])
		{
			if (!c[str[i]])
				c[str[i]] = true;
			++i;
		}
		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (c[str[i]])
			{
				write(STDOUT_FILENO, str + i, 1);
				c[str[i]] = false;
			}
			++i;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}