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

int	get_next_line(int fd, char **line)
{
	int ret;
	char buffer[BUFFER_SIZE + 1];
	static char *save_line;

	if (fd < 0)
		return (-1);
	while((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (save_line == NULL)
			save_line = ft_strdup(buffer);
		else
			tmp = ft_strjoin(save_line, buffer);
			save = tmp;
		if (ft_strchr(save_line, '\n'))
			break;
	}
	
}