//
// Created by Funky on 12.12.2022.
//
#include "get_next_line.h"

int main()
{
	char	*line = NULL;
	int		fd = open("main.c", O_RDONLY);

	if (!fd)
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
}