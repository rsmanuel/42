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

char *ft_itox(unsigned long nb, t_struct *params)
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
		return (NULL);
	str[len + 1] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[nb % 16];
		nb /= 16;
		len--;
	}
	return (str);
}

void	ft_precision_d(t_struct *params)
{
	int	len;
	int	i;

	len = ft_strlen(params->str);
	i = len;
	if (params->precision > len)
	{
		while (i < params->precision)
		{
			ft_putchar_fd('0', 1);
			i++;
			params->len++;
			params->ret++;
		}
	}
}

void	treat_precision(t_struct *params)
{
	if (params->width > params->precision && !params->minus)
	{
		if (params->nb < 0 && params->precision >= 0)
			params->width -= 1;
		if (params->precision == 0)
			ft_width(params, (params->width - params->len));
		else
			ft_width(params, (params->width - params->precision));
	}
	if (params->nb < 0 && params->nb != -2147483648)
	{
		ft_putchar_fd('-', 1);
		params->len++;
	}
	ft_precision_d(params);
	if (!(!params->precision && params->str[0] == '0'))
	{
		ft_putstr_fd(params->str, 1);
		params->ret += ft_strlen(params->str);
	}
	if (params->width > params->precision && params->minus)
		ft_width(params, (params->width - params->len));
	return ;
}

void	print_x_aux(t_struct *params)
{
	char	*str;

	str = params->str;
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		if (params->zero && params->width && !params->minus)
		{
			if (params->nb < 0)
			{
				ft_putchar_fd('-', 1);
				params->len++;
			}
			ft_zero(params, (params->width - params->len));
		}
		if (params->nb < 0 && !params->zero)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(str, 1);
		params->ret += ft_strlen(str);
		if (params->minus)
			ft_width(params, (params->width - params->len));
	}
}

void	print_x(va_list ap, t_struct *params)
{
	unsigned int nb;
	char *str;

	nb = va_arg(ap, unsigned int);
	if (!nb)
		return;
	str = ft_itox(nb, params);
	ft_putstr_fd(str, 1);
	params->ret++;
	if (nb)
		free(str);
}
