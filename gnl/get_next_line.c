/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:43:52 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/01 18:08:33 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (-1);
	if (dstsize == 0)
	{
		while (src[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

int			ft_strlen(char const *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return(len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (0);
	i = 0;
	k = 0;
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		s3[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[k] = s2[i];
		i++;
		k++;
	}
	s3[k] = '\0';
	return (s3);
}

int	findnl(char *new_line)
{
	int i;

	i = 0;
	while (new_line[i] != '\0')
	{
		if (new_line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}	

int	get_next_line(int fd, char **line)
{
	static char	*new_line;
	char		buffer[BUFFER_SIZE];
	int		ret;
	char *tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	new_line = NULL;
	while (findnl(new_line) == 1 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret + 1] = '\0';
		tmp = ft_strjoin(new_line, buffer);
		tmp = new_line;
		free(new_line);
	}
	if (ret == 0)
		*line = ft_strdup(new_line);
	return (0);
}
