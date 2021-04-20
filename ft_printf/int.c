#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	conversion_is_x_u(t_struct *params)
{
	if (params->width > params->precision && !params->minus)
	{
		if (params->width > params->precision
			&& params->precision < params->len)
			ft_width(params, (params->width - params->len));
		else
			ft_width(params, (params->width - params->precision));
	}
}

void	treat_precision(t_struct *params)
{
	if (params->width > params->precision && !params->minus
		&& (params->conversion == 'd' || params->conversion == 'i'))
	{
		if (params->nb < 0 && params->precision >= 0 && params->nb != INT_MIN)
			params->width -= 1;
		if (params->precision > params->len)
			ft_width(params, (params->width - params->precision));
		else
			ft_width(params, (params->width - params->len));
	}
	if (params->nb < 0 && params->nb != INT_MIN)
	{
		ft_putchar_fd('-', 1);
		params->ret++;
		params->len++;
	}
	if (params->conversion != 'd' && params->conversion != 'i')
		conversion_is_x_u(params);
	ft_precision(params);
	if (!(!params->precision && params->str[0] == '0'))
	{
		ft_putstr_fd(params->str, 1);
		params->ret += ft_strlen(params->str);
	}
	if (params->width > params->precision && params->minus)
		ft_width(params, (params->width - params->len));
}

void	print_d_aux(t_struct *params)
{
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		if (!params->minus && params->width && !params->zero)
		{
			if (params->nb < 0)
				params->len += 1;
			ft_width(params, (params->width - params->len));
		}
		if (params->zero && params->width && !params->minus)
		{
			if (params->nb < 0)
			{
				if (params->nb != INT_MIN)
				{
					ft_putchar_fd('-', 1);
					params->ret += 1;
				}
				params->len++;
			}
			ft_zero(params, (params->width - params->len));
		}
		if (params->nb < 0 && !params->zero && params->nb != INT_MIN)
		{
			ft_putchar_fd('-', 1);
			params->ret += 1;
		}
		ft_putstr_fd(params->str, 1);
		params->ret += ft_strlen(params->str);
		if (params->nb < 0 && !params->zero)
			params->len += 1;
		if (params->minus)
			ft_width(params, (params->width - params->len));
	}
}

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;

	nb = va_arg(ap, int);
	params->nb = nb;
	str = ft_itoa(nb);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
		if (params->nb < 0 && params->nb != INT_MIN && !params->zero && params->precision == -1)
			params->ret++;
	}
	params->len = ft_strlen(str);
	if (!params->precision && str[0] == '0')
		params->len = 0;
	params->str = str;
	if (nb < 0 && params->zero && params->minus && params->precision == -1 && params->nb != INT_MIN)
	{
		ft_putchar_fd('-', 1);
		params->len++;
	}
	print_d_aux(params);
	free(str);
}
