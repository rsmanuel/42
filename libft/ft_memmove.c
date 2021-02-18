/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:37:17 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/18 20:34:37 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!len)
		return (dst);
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
		while (i < len)
		{
			d[len - 1 - i] = s[len - 1 - i];
			i++;
		}
	return (dst);
}
