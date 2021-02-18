/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:34:38 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/08 18:34:39 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			slen;
	unsigned int	i;

	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	i = 0;
	slen = ft_strlen(s);
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
