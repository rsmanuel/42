#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

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

void parse_flags(const char *str, va_list ap, t_struct *params)
{
	while(ft_strchr("-+ 0#", *str)
	{
		if (*str == '-')
			params->minus = 1;
		else if (*str == '+')
			params->plus = 1;
		else if (*str == ' ')
			params->space = 1;
		else if (*str == '0')
			params->zero = 1;
		else if (*str == '#')
			params->hash = 1;
		i++;
	}
}

void parse_modifiers(const char *str, va_list ap, t_struct *params)
{

}

void print(char conversion, va_list ap, t_struct *params)
{
	if (conversion == 'c')
		print_c(ap);
	else if (conversion == 's')
		print_s(ap);
	else if (conversion == 'd')
		print_d(ap);
}

int	parse_str(const char *str, va_list ap, t_struct *params)
{
	int len;
	char *conversion;

	len = 0;
	conversion = NULL;
	//parse modifiers function (deals with everything
	//between % and the conversion symbol
	while (ft_strchr("-. 0*#+cspdiuxX123456789", *str))
	{
		len++;
		conversion = ft_strchr("cspdiuxX", *str);
		if (conversion)
			break;
		str++;
	}
	if (!conversion)
		return (0);
	print(*conversion, ap, params);
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	int modifier_len;
	int i;
	va_list ap;
	t_struct *params;
	
	i = 0;
	va_start(ap, fmt);
	params = (t_struct *)malloc(sizeof(t_struct));
	reset_struct(params);
	if (!params)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i += parse_str(&fmt[i + 1], ap, params); 
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
	}
	va_end(ap);
	free(params);
	return (0);
}

int main(void)
{
	ft_printf("%d ola %s", 1, "this is a string");
}
