/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:12:32 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/25 17:23:45 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_buf_save(char *buf_save, char *buf)
{
	char *saved;
	int i;
	int j;

	if(!buf_save || !buf)
		return(0);
	i = 0;
	j = 0;
	if (!(saved = malloc(sizeof(char) * (ft_strlen(buf_save) + ft_strlen(buf) + 1))))
		return (0);
	while (buf_save[i] != '\0')
	{
		saved[j] = buf_save[i];
		i++;
		j++; 
	}
	i = 0;
	while (buf[i] != '\0')
	{
		saved[j] = buf[i];
		i++;
		j++;
	}
	saved[j] = '\0';
	return (saved);
}



int	get_next_line(int fd, char **line)
{
	static char	*buf_save;
	char	*buf;
	int	buf_size;

	if(fd < 0 || !line || BUFFER_SIZE <= 0)
		return(-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	buf_size = read(fd, buf, BUFFER_SIZE);
	while (buf_size != 0 && check_nl(buf_save) == 1)
	{
		if (buf_size == -1)
		{
			free(buf);
			return (-1);			
		}
		buf[buf_size] = '\0';
		buf_save = make_buf_save(buf_save, buf);
	}
	free(buf);
	
	if (buf_size == 0)
		return (0);
	return (1);
}
