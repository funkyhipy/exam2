/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:25:42 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/20 12:25:44 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int main(void)
{
	char	*line = NULL;
	int		fd = open("Makefile", O_RDONLY);

	if (fd >= 0)
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
	printf("\nexit");
	return (0);
}
 */

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char	*line, *tmp, *delim;

	if (!str)
		str = ft_calloc(1, sizeof (char));
	delim = ft_strchr(str, '\n');
	if (delim)
	{
		line = ft_line(str, delim);
		ft_next(delim, &str);
		return (line);
	}
	line = ft_readfile(fd);
	tmp = ft_strjoin(str, line);
	free(line);
	delim = ft_strchr(tmp, '\n');
	line = ft_line(tmp, delim);
	ft_next(delim, &str);
	free(tmp);
	return (line);
}

char	*ft_readfile(int fd)
{
	char	*line, *buf, *tmp;
	size_t	r;

	r = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	line = ft_calloc(1, sizeof (char));
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r != BUFFER_SIZE || ft_strchr(buf, '\n'))
		{
			tmp = ft_strjoin(line, buf);
			free(line);
			free(buf);
			return (tmp);
		}
		tmp = line;
		line = ft_strjoin(tmp, buf);
		free(tmp);
		ft_bzero(buf, BUFFER_SIZE);
	}
	free(buf);
	return (line);
}

char	*ft_next(const char *delim, char **buf)
{
	char	*next;
	size_t	li_len;

	if (!delim)
	{
		ft_free(buf);
		return (NULL);
	}
	++delim;
	li_len = ft_strlen(delim);
	next = ft_calloc(li_len + 1, sizeof (char));
	ft_memcpy(next, delim, li_len);
	ft_free(buf);
	*buf = next;
	return (next);
}

char	*ft_line(const char *str, const char *delim)
{
	char	*line;
	size_t	li_len;

	li_len = ft_strlen(str) - ft_strlen(delim);
	if (delim)
		++li_len;
	if (!li_len)
		return (NULL);
	line = ft_calloc(li_len + 1, sizeof (char));
	ft_memcpy(line, str, li_len);
	return (line);
}
void	ft_memcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (dest && src && size)
	{
		i = 0;
		while (i < size)
		{
			dest[i] = src[i];
			++i;
		}
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof (char));
	if (!str)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			str[i] = *(s1)++;
		else
			str[i] = *(s2)++;
		++i;
	}
	return (str);
}

char	*ft_strchr(const char *str, const char c)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
			return (&ptr[i]);
		++i;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*ptr;

	n = count * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			++i;
	}
	return (i);
}

void	ft_bzero(char *ptr, size_t size)
{
	size_t	i;

	if (ptr)
	{
		i = 0;
		while (i < size)
		{
			ptr[i] = 0;
			++i;
		}
	}
}

void	ft_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}