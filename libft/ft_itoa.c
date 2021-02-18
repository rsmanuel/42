/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:54:49 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/18 15:55:46 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	n_sign(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static char	*int_min(int n, int len)
{
	char	*strn;

	strn = (char *)malloc(sizeof(char) * len + 1);
	if (strn == NULL)
		return (0);
	if (n == -2147483648)
	{
		strn = ft_strdup("-2147483648");
		return (strn);
	}
	if (n == 0)
	{
		strn = ft_strdup("0");
		return (strn);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*strn;

	len = n_len(n);
	strn = (char *)malloc(sizeof(char) * (len + 1));
	if (strn == NULL)
		return (0);
	strn[len] = '\0';
	if (n == -2147483648 || n == 0)
	{
		strn = int_min(n, len);
		return (strn);
	}
	if (n < 0)
	{
		n = n_sign(n);
		strn[0] = '-';
	}
	while (n != 0)
	{
		len--;
		strn[len] = n % 10 + '0';
		n = n / 10;
	}
	return (strn);
}
