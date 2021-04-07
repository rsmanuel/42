#include "libft/libft.h"
#include "ft_printf.h"

void	ft_precision_d(t_struct *params)
{
	int len;
	int i;

	len = params->len;
	i = len;
	if (params->precision > len)
	{
		if (params->nb < 0)
		{
			ft_putchar_fd('0', 1);
			params->ret++;
			params->len++;
		}
		while (i < params->precision)
		{
			ft_putchar_fd('0', 1);
			i++;
			params->len++;
			params->ret++;
		}
	}
	else
		return ; 
}

void treat_precision(t_struct *params)
{
	if (!params->precision && params->str[0] == '0')
		return;
	if (params->width > params->precision && !params->minus)
	{
		if (params->nb < 0)
			params->width--;
		ft_width(params, params->width - params->precision);
	}
	if (params->nb < 0)
		ft_putchar_fd('-', 1);
	ft_precision_d(params);
	ft_putstr_fd(params->str, 1);
	params->ret += ft_strlen(params->str);
	if (params->width > params->precision && params->minus)
	{
		ft_width(params, params->width - params->len);
	}
}

void	print_d_aux(t_struct *params)
{
	char	*str;

	str = params->str;
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		ft_putstr_fd(str, 1);
		params->ret += ft_strlen(str);
	}
}

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;
	int		len;
 
	nb = va_arg(ap, int);
	params->nb = nb;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
	}
	params->str = str;
	params->number = nb;
	params->len = len;
	print_d_aux(params);
	free(str);
}
