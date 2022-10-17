#include <stdbool.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	bool	c[256];
	int		i, j;
	char	*str;

	if (argc == 3)
	{
		i = 0;
		while (i < 256)
			c[i++] = false;
		i = 1;
		while (i < 3)
		{
			str = argv[i];
			j = 0;
			while (str[j])
			{
				if (!c[str[j]])
				{
					c[str[j]] = true;
					write(STDOUT_FILENO, str +j, 1);
				}
				++j;
			}
			++i;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}