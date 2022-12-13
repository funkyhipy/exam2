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

#include <get_next_line.h>

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
	printf("exit");
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char	*line, *tmp;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	if (ft_strchr(str, '\n'))
	{
		line = ft_line(str);
		ft_next(str, &str);
		return (line);
	}
	line = ft_readfile(fd);
	tmp = ft_strjoin(str, line);
	free(line);
	line = ft_line(tmp);
	ft_next(tmp, &str);
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
		if (ft_strchr(buf, '\n') || r != BUFFER_SIZE)
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

char	*ft_next(const char *str, char **buf)
{
	char	*next, *delim;
	size_t	li_len, i;

	delim = ft_strchr(str, '\n');
	if (delim)
	{
		++delim;
		li_len = ft_strlen(delim);
		next = ft_calloc(li_len + 1, sizeof (char));
		i = 0;
		while (i < li_len)
		{
			next[i] = delim[i];
			++i;
		}
		ft_free(*buf);
		*buf = next;
		return (next);
	}
	return (NULL);
}

char	*ft_line(const char *str)
{
	char	*line, *delim;
	size_t	li_len, i;

	delim = ft_strchr(str, '\n');
	li_len = ft_strlen(str) - ft_strlen(delim);
	if (delim)
		li_len++;
	if (!li_len)
		return (NULL);
	line = ft_calloc(li_len + 1, sizeof (char));
	i = 0;
	while (i < li_len)
	{
		line[i] = str[i];
		++i;
	}
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s)
	{
		while (s[count])
			count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t 	i;
	char 	*str;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			str[i] = *(s1)++;
		else
			str[i] = *(s2)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	n;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	n = nmemb * size;
	while (n--)
	{
		*str++ = 0;
	}
	return (ptr);
}

void	ft_bzero(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		++i;
	}
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
