/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:06:56 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/09 11:34:08 by rmanuel          ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*newb;

	newb = (char *)b;
	while (len > 0)
	{
		newb[len - 1] = c;
		len--;
	}
	return (b);
}
