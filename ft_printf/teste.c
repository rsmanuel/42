/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:45:48 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/17 18:29:05 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_printf(char const *str, ...)
{
	va_list ap;
	char c, *s;
	int d, i;
	
	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				va_arg(ap, int);
				printf("%c", c);
			}
			else if (str[i] == 's')
			{
				va_arg(ap, char *);
				printf("%s", s);
			}
			else if (str[i] == 'd')
			{
				va_arg(ap, int);
				printf("%d", d);
			}
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(ap);
}

int main(void)
{
	ft_printf("%s asdasdjhsfkjas %d    %c", "rodrigo", 1, 'c');
}
