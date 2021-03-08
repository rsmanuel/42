/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:56:47 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/08 18:36:18 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*make_line(char *save, char **line)
{
	int i_nl;
	char *saved;

	i_nl = find_nl(save);
	if (i_nl == -1)
	{
		*line = ft_strdup(save);
		free(save);
		save = NULL;
		return (save);
	}
	save[i_nl] = '\0';
	*line = malloc(sizeof(char) * i_nl + 1);
	saved = ft_strdup(&save[i_nl + 1]);
	ft_strlcpy(*line, save, i_nl + 1);
	free(save);
	save = NULL;
	return (saved);
}

int	get_next_line(int fd, char **line)
{
	int ret;
	static char *save;
	char *buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (save == NULL)
		save = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 1;
	while (ret > 0 && find_nl(save) == -1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		save = ft_strjoin(save, buffer);
	}
	if (ret > 0)
	{
		save = make_line(save, line);
		free(buffer);
		return (1);
	}
	else
		return (0);
}
