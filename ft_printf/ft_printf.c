#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>

void	print_c(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1); 
}

void	print_s(va_list ap)
{
	ft_putstr_fd(va_arg(ap, char *), 1);
}

void	print_d(va_list ap)
{
	ft_putnbr_fd(va_arg(ap, int), 1);
}

int	format(const char *str, va_list ap)
{
	int len;
	char *modifier;

	len = 0;
	modifier = NULL;
	while (ft_strchr("-. 0*#+cspdiuxX123456789", *str))
	{
		len++;
		modifier = ft_strchr("cspdiuxX", *str);
		if (modifier)
			break;
		str++;
	}
	if (!modifier)
		return (0);
	if (*modifier == 'c')
		print_c(ap);
	else if (*modifier == 's')
		print_s(ap);
	else if (*modifier == 'd')
		print_d(ap);
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	int modifier_len;
	int i;
	va_list ap;
	
	i = 0;
	va_start(ap, fmt);
	//create struct with flags
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			modifier_len = format(&fmt[i + 1], ap);
			i += modifier_len; 
		}
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	//printf("|%c| |%s| |%€d|", 'a', "rodrigo", 1);
	ft_printf("|%c| |%s| |%€d|", 'a', "rodrigo", 1);
}