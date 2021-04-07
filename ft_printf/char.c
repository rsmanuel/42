#include "libft/libft.h"
#include "ft_printf.h"

void	print_c_aux(t_struct *params, int len, char c)
{
	if (!params->minus && params->width >= 0 && !params->zero)
		ft_width(params, len);
	if (params->zero && params->width && !params->minus && !params->precision)
		ft_zero(params, len);
	ft_putchar_fd(c, 1);
	if (params->minus || params->width < 0)
		ft_width(params, len);
	params->ret++;
}

void	print_c(va_list ap, t_struct *params)
{
	char	c;

	c = va_arg(ap, int);
	print_c_aux(params, 1, c);
}

