/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:37:17 by rmanuel           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/24 11:02:13 by rmanuel          ###   ########.fr       */
=======
/*   Updated: 2021/02/23 21:07:43 by rmanuel          ###   ########.fr       */
>>>>>>> e8ec59fcb3e4b4004c4e258e4265b93f32b7e493
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;
<<<<<<< HEAD

=======
	
>>>>>>> e8ec59fcb3e4b4004c4e258e4265b93f32b7e493
	if (!dst && !src)
		return (0);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s >= d)
		return (ft_memcpy(d, s, len));
	else
	{
		while (i < len)
		{
			d[len - 1 - i] = s[len - 1 - i];
			i++;
		}
	}
<<<<<<< HEAD
	return (d);
=======
	return (dst);
>>>>>>> e8ec59fcb3e4b4004c4e258e4265b93f32b7e493
}
