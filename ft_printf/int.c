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
	if ((params->minus || params->zero) && nb < 0)
	{
		str = ft_itoa(-nb);
		ft_putchar_fd('-', 1);
	}
	params->str = str;
	if ((params->plus || params->space) && nb >= 0)
		len++;
	//printf("\nzero: %d\n", params->zero);
	//printf("\nminus: %d\n", params->minus);
	//printf("\nwidth: %d\n", params->width);
	//printf("\nprecision: %d\n", params->precision);
	print_d_aux(params, len, nb, str, count);
	free(str);
}

void	print_d_aux(t_struct *params, int len, int nb, char *str, t_count *count)
{
	if (params->space && nb >= 0)
		ft_putchar_fd(' ', 1);
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len, count);
	if (params->plus && nb >= 0)
		ft_putchar_fd('+', 1);
	if (params->zero && params->width && !params->minus && params->precision == -1)
		ft_zero(params, len, count);
	if (params->precision > -1)
		ft_zero(params, len, count);
	ft_putstr_fd(str, 1);
	count->ret += ft_strlen(str);
	if (params->minus)
		ft_width(params, len, count);
}
