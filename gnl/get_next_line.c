/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:44:39 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/04 16:06:29 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			slen;
	unsigned int	i;

	slen = ft_strlen(s);
	if (len > slen)
		sub = (char *)malloc(sizeof(char) * (slen + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	i = 0;
	if (!s)
		return (0);
	if (start < slen)
	{
		while (i < len && s[start] != '\0')
		{
			sub[i] = s[start];
			i++;
			start++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	newc;

	str = (char *)s;
	len = ft_strlen(str);
	newc = (char)c;
	while (len != 0 && str[len] != newc)
		len--;
	if (str[len] == newc)
		return (&str[len]);
	return (NULL);
}

int	return_values(char *save, char **line, int ret)
{
	int len;
	char *tmp;
	
	len = 0;
	if (ret < 0)
		return (-1);
	else if (ret == 0)
	{
		*line = ft_strdup(save);
		return (0);
	}
	else
	{
		while (save[len] != '\n' || save[len] != '\0')
			len++;
		*line = ft_substr(save, 0, len);
		tmp = ft_strdup(&save[len + 1]);
		free(save);
		save = tmp;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int	ret;
	char buffer[BUFFER_SIZE + 1];
	static char *save;
	char *tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
			tmp = ft_strjoin(save, buffer);
			save = tmp;
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (return_values(save, line, ret));	
}
