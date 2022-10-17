/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:25:42 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/20 12:25:44 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char	*ft_free(char *rem, char *buf)
{
	char	*temp;

	temp = ft_strjoin(rem, buf);
	free(rem);
	return (temp);
}

static char	*ft_next(char *rem)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (!rem[i])
	{
		free(rem);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(rem) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rem[i])
		line[j++] = rem[i++];
	free(rem);
	return (line);
}

static char	*ft_line(const char *rem)
{
	char	*line;
	int		i;

	i = 0;
	if (!rem[i])
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (rem[i] && rem[i] != '\n')
	{
		line[i] = rem[i];
		i++;
	}
	if (rem[i] && rem[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		r;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	r = 1;
	while (r > 0 && !ft_strchr(buffer, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = 0;
		res = ft_free(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
