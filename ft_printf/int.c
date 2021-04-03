#include "libft/libft.h"
#include "ft_printf.h"

void	print_d(va_list ap, t_struct *params, t_count *count)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(ap, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
		ft_putchar_fd('-', 1);
	}
	params->str = str;
	if ((params->plus || params->space) && nb >= 0)
		len++;
	print_d_aux(params, len, nb, str, count);
	free(str);
}

void	ft_precision_d(t_struct *params, int len, char *str, t_count *count)
{
	int	i;

	i = 0;
	if (params->width && !params->minus)
			ft_width(params, params->precision, count);
	while (i < params->precision - len)
	{
		ft_putchar_fd('0', 1);
		count->ret++;
		i++;
	}
	if (params->precision == 0 && str[0] == '0')
		return ;
	ft_putstr_fd(str, 1);
	count->ret += 1 * len;
}

void	print_d_aux(t_struct *params, int len, int nb, char *str, t_count *count)
{
	/*
	if (params->precision > -1)
		ft_precision(params, len, str, count);
	if (params->space && nb >= 0)
		ft_putchar_fd(' ', 1);
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len, count);
	if (params->plus && nb >= 0)
		ft_putchar_fd('+', 1);
	if (params->zero && params->width && !params->minus)
		ft_zero(params, len, count);
	if (params->minus)
		ft_width(params, len, count);
	ft_putstr_fd(str, 1);
	count->ret += ft_strlen(str);
	*/
	if (params->precision > -1)
	{
		if (nb < 0 && len < params->precision)
			ft_putchar_fd('0', 1);
		ft_precision_d(params, len, str, count);
		if (params->minus && len <= params->precision)
			ft_width(params, (params->precision - len) + len , count);
		else if (params->minus && len > params->precision)
			ft_width(params, len , count);
		return ;
	}
	if (params->width && !params->minus)
	{
		if (params->zero)
			ft_zero(params, len, count);
		else
			ft_width(params, len, count);
	}
	ft_putstr_fd(str, 1);
	count->ret += ft_strlen(str);
	if (params->minus)
		ft_width(params, len , count);
}
