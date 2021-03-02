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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


int	ft_strlen_nl(char **save_line)
{
	int len;

	len = 0;
	while (*save_line[len] != '\0')
	{
		if (*save_line[len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

int	return_values(char **save_line, char **line, int ret)
{
	int len;
	char *tmp;

	len = 0;
	if(ret < 0)
		return (-1);
	else if (ret == 0)
	{
		if (save_line == NULL)
			*line = ft_strdup("");
		else if (save_line != NULL)
		{
			*line = ft_strdup(*save_line);
			free(*save_line);
			*save_line = NULL;
		}
		return(0);
	}
	else
		len = ft_strlen_nl(save_line);
		if (*save_line[len] == '\n')
		{
			*line = ft_substr(*save_line, 0, len);
			tmp = ft_strdup(&(*save_line[len + 1]));
			free(save_line);
			*save_line = tmp;
		}
		else
		{
			*line = ft_strdup(*save_line);
			free(*save_line);
			*save_line = NULL;
			return (0);
		}
	return (1); 
}

int	get_next_line(int fd, char **line)
{
	int ret;
	char buffer[BUFFER_SIZE + 1];
	static char *save_line;
	char *tmp;

	if (fd < 0)
		return (-1);
	while((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (save_line == NULL)
			save_line = ft_strdup(buffer);
		else
			tmp = ft_strjoin(save_line, buffer);
			free(save_line);
			save_line = tmp;
		if (ft_strchr(save_line, '\n'))
			break;
	}
	return(return_values(&save_line, line, ret));
}