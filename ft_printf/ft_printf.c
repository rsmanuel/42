//cspdiuxX
#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>

void	format(const char *str, va_list ap)
{
	char *modifier;
	//find modifier (s, d, c, ...)
	while (*str)
	{
		modifier = ft_strchr("cspdiuxX", *str);
		if (modifier)
			break;
		str++;
	}
	printf("modifier: %c\n", *modifier);
	//call corresponding function (e.g. format_string, format_int)
}

int		ft_printf(const char *fmt, ...)
{
	int i;
	va_list ap;
	
	i = 0;
	va_start(ap, fmt);
	//create struct with flags
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			format(&fmt[i], ap);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("%d %s asdasda % -.s");
}
