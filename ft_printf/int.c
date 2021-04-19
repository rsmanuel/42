#include "libft/libft.h"
#include "ft_printf.h"

void	ft_precision(t_struct *params)
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
	if (params->nb >= 0 && params->plus)
	{
		ft_putchar_fd('+', 1);
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
	char	*str;

	str = params->str;
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		if ((params->zero && params->width && !params->minus) || (params->zero && params->width && !params->minus && params->plus))
		{
			if (params->nb < 0)
			{
				ft_putchar_fd('-', 1);
				params->len++;
			}
			if (params->nb >= 0)
			{
				ft_putchar_fd('+', 1);
				params->ret++;
				params->len++;
			}
			ft_zero(params, (params->width - params->len));
		}
		if (params->nb < 0 && !params->zero)
			ft_putchar_fd('-', 1);
		if (params->nb >= 0 && !params->zero)
		{
			ft_putchar_fd('+', 1);
			params->ret++;
		}
		ft_putstr_fd(str, 1);
		params->ret += ft_strlen(str);
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
		if (nb != -2147483648)
			params->ret++;
	}
	params->len = ft_strlen(str);
	if (!params->precision && str[0] == '0')
		params->len = 0;
	params->str = str;
	if (nb < 0 && params->zero && params->minus && params->precision == -1)
	{
		ft_putchar_fd('-', 1);
		params->len++;
	}
	print_d_aux(params);
	free(str);
}
