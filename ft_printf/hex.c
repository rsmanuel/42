#include "libft/libft.h"
#include "ft_printf.h"

int	len_itox(unsigned long nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void ft_itox(unsigned long nb, t_struct *params)
{
	int	len;
	char *base;
	char *str;

	len = len_itox(nb);
	if (params->conversion == 'X')
		base = "0123456789ABCDEF";
	else if (params->conversion == 'x')
		base = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	str[len + 1] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[nb % 16];
		nb /= 16;
		len--;
	}
	params->str = str;
	free(str);
}

void	print_x_aux(t_struct *params)
{
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		if (params->zero && params->width && !params->minus)
			ft_zero(params, (params->width - params->len));
		ft_putstr_fd(params->str, 1);
		params->ret += ft_strlen(params->str);
		if (params->minus)
			ft_width(params, (params->width - params->len));
	}
}

void	print_x(va_list ap, t_struct *params)
{
	unsigned int nb;

	nb = va_arg(ap, unsigned int);
	ft_itox(nb, params);
	params->len = ft_strlen(params->str);
	printf("<<%s>>", params->str);
	print_x_aux(params);
}
