#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

void debug_params(t_struct *params)
{
	printf("\tminus: \t\t%d\n", params->minus);
	printf("\tplus: \t\t%d\n", params->plus);
	printf("\tzero: \t\t%d\n", params->zero);
	printf("\tspace: \t\t%d\n", params->space);
	printf("\thash: \t\t%d\n", params->hash);
	printf("\twidth: \t\t%d\n", params->width);
	printf("\tprecision: \t%d\n", params->precision);
	printf("\n\n");
}

int nb_len(int nb)
{
	int len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void print_width(t_struct *params, va_list ap)
{
	int width;
	int nb;
	
	nb = nb_len(print_d(params));
	width = (params->width) - nb;
	if (params->zero)
	{
		while (--width >= 0)
			ft_putchar_fd('0', 1);
	}
	while (--width >= 0)
		ft_putchar_fd(' ', 1);
}

void	print_c(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1); 
}

void	print_s(va_list ap)
{
	ft_putstr_fd(va_arg(ap, char *), 1);
}

int	print_d(va_list ap, t_struct *params)
{
	int nb;
	if (params->width)
		print_width(params ,ap);
	nb = ft_putnbr_fd(va_arg(ap, int), 1);
	return (nb);
}

void parse_flags(const char *str, va_list ap, t_struct *params)
{
	while(ft_strchr("-+ 0#", *str))
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
		str++;
	}
}
void parse_precision(const char *str, va_list ap, t_struct *params)
{

}

void parse_width(const char *str, va_list ap, t_struct *params)
{
	int i;
	int start;
	int width;

	i = 0;
	start = 0;
	while (ft_strchr("-+ 0#", str[i]))
		i++;
	start = i;
	if (str[i] == '*')
	{
		params->width = va_arg(ap, int);
		return ;
	}
	while (ft_strchr("0123456789", str[i]))
			i++;
	params->width = ft_atoi(ft_substr(str, start, i - start));
}


void parse_modifiers(const char *str, va_list ap, t_struct *params)
{
	parse_flags(str, ap, params);
	parse_width(str, ap, params);
	debug_params(params);
}

void print(char conversion, va_list ap, t_struct *params)
{
	if (conversion == 'c')
		print_c(ap);
	else if (conversion == 's')
		print_s(ap);
	else if (conversion == 'd')
		print_d(ap, params);
}

int	parse_str(const char *str, va_list ap, t_struct *params)
{
	int len;
	char *conversion;

	len = 0;
	conversion = NULL;
	parse_modifiers(str, ap, params);
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
	ft_printf("%02d", 5);
	printf("\n%02d", 5);
}