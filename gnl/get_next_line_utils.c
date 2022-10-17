/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:25:59 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/20 12:26:01 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/*
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

 */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i++ <= (int)ft_strlen(s))
	{
		if (*str == (char)c)
			return (str);
		str++;
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
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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

/*
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
*/