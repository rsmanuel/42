/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:43:52 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/01 14:58:09 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	new_line = NULL;
	while (findnl(new_line) == 1 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret + 1] = '\0';
		new_line = ft_strjoin(new_line, buffer);
		free(new_line);
	}
	if (r > 0)
		*line = new_line;
}
