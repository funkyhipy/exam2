/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:26:16 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/20 12:26:17 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif // BUFFER_SIZE

char	*get_next_line(int fd);

void	ft_free(char **ptr);
void	ft_bzero(char *ptr, size_t size);
char	*ft_readfile(int fd);
char	*ft_line(const char *str, const char *delim);
char	*ft_next(const char *delim, char **buf);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, const char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_memcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(char *str, size_t size);
#endif // GET_NEXT_LINE_BONUS_H
